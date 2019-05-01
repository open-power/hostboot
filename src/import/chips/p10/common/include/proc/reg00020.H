/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00020.H $         */
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

#ifndef __PROC_REG00020_H_
#define __PROC_REG00020_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_CFG_STQ1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010818;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_CFG_STQ1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010818;
#endif
    return fapi2::getScom(i_target, INT_CQ_CFG_STQ1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_CFG_STQ1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return fapi2::putScom(i_target, INT_CQ_CFG_STQ1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_IPI_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_IPI_MIN_0_2,
           INT_CQ_CFG_STQ1_IPI_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_IPI_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_IPI_MIN_0_2,
           INT_CQ_CFG_STQ1_IPI_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_IPI_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_IPI_MIN_0_2,
           INT_CQ_CFG_STQ1_IPI_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_IPI_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_IPI_MAX_0_4,
           INT_CQ_CFG_STQ1_IPI_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_IPI_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_IPI_MAX_0_4,
           INT_CQ_CFG_STQ1_IPI_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_IPI_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_IPI_MAX_0_4,
           INT_CQ_CFG_STQ1_IPI_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_IPI_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HW_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HW_MIN_0_2,
           INT_CQ_CFG_STQ1_HW_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HW_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HW_MIN_0_2,
           INT_CQ_CFG_STQ1_HW_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_HW_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_HW_MIN_0_2,
           INT_CQ_CFG_STQ1_HW_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HW_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HW_MAX_0_4,
           INT_CQ_CFG_STQ1_HW_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HW_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HW_MAX_0_4,
           INT_CQ_CFG_STQ1_HW_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_HW_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_HW_MAX_0_4,
           INT_CQ_CFG_STQ1_HW_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HW_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_NXCQ_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_NXCQ_MIN_0_2,
           INT_CQ_CFG_STQ1_NXCQ_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_NXCQ_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_NXCQ_MIN_0_2,
           INT_CQ_CFG_STQ1_NXCQ_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_NXCQ_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_NXCQ_MIN_0_2,
           INT_CQ_CFG_STQ1_NXCQ_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_NXCQ_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_NXCQ_MAX_0_4,
           INT_CQ_CFG_STQ1_NXCQ_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_NXCQ_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_NXCQ_MAX_0_4,
           INT_CQ_CFG_STQ1_NXCQ_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_NXCQ_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_NXCQ_MAX_0_4,
           INT_CQ_CFG_STQ1_NXCQ_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_NXCQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_INTQ_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_INTQ_MIN_0_2,
           INT_CQ_CFG_STQ1_INTQ_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_INTQ_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_INTQ_MIN_0_2,
           INT_CQ_CFG_STQ1_INTQ_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_INTQ_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_INTQ_MIN_0_2,
           INT_CQ_CFG_STQ1_INTQ_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_INTQ_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_INTQ_MAX_0_4,
           INT_CQ_CFG_STQ1_INTQ_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_INTQ_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_INTQ_MAX_0_4,
           INT_CQ_CFG_STQ1_INTQ_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_INTQ_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_INTQ_MAX_0_4,
           INT_CQ_CFG_STQ1_INTQ_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_INTQ_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_OS_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_OS_MIN_0_2,
           INT_CQ_CFG_STQ1_OS_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_OS_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_OS_MIN_0_2,
           INT_CQ_CFG_STQ1_OS_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_OS_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_OS_MIN_0_2,
           INT_CQ_CFG_STQ1_OS_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_OS_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_OS_MAX_0_4,
           INT_CQ_CFG_STQ1_OS_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_OS_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_OS_MAX_0_4,
           INT_CQ_CFG_STQ1_OS_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_OS_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_OS_MAX_0_4,
           INT_CQ_CFG_STQ1_OS_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_OS_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_POOL_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_POOL_MIN_0_2,
           INT_CQ_CFG_STQ1_POOL_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_POOL_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_POOL_MIN_0_2,
           INT_CQ_CFG_STQ1_POOL_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_POOL_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_POOL_MIN_0_2,
           INT_CQ_CFG_STQ1_POOL_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_POOL_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_POOL_MAX_0_4,
           INT_CQ_CFG_STQ1_POOL_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_POOL_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_POOL_MAX_0_4,
           INT_CQ_CFG_STQ1_POOL_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_POOL_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_POOL_MAX_0_4,
           INT_CQ_CFG_STQ1_POOL_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_POOL_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HARD_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HARD_MIN_0_2,
           INT_CQ_CFG_STQ1_HARD_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HARD_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HARD_MIN_0_2,
           INT_CQ_CFG_STQ1_HARD_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_HARD_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_HARD_MIN_0_2,
           INT_CQ_CFG_STQ1_HARD_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HARD_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HARD_MAX_0_4,
           INT_CQ_CFG_STQ1_HARD_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_HARD_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_HARD_MAX_0_4,
           INT_CQ_CFG_STQ1_HARD_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_HARD_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_HARD_MAX_0_4,
           INT_CQ_CFG_STQ1_HARD_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_HARD_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_THR_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_THR_MIN_0_2,
           INT_CQ_CFG_STQ1_THR_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_THR_MIN_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_THR_MIN_0_2,
           INT_CQ_CFG_STQ1_THR_MIN_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_THR_MIN_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_THR_MIN_0_2,
           INT_CQ_CFG_STQ1_THR_MIN_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MIN_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_THR_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_THR_MAX_0_4,
           INT_CQ_CFG_STQ1_THR_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_CFG_STQ1_THR_MAX_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return o_data.insertFromRight<INT_CQ_CFG_STQ1_THR_MAX_0_4,
           INT_CQ_CFG_STQ1_THR_MAX_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_CFG_STQ1_THR_MAX_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010818));
#endif
    return i_data.extractToRight<INT_CQ_CFG_STQ1_THR_MAX_0_4,
           INT_CQ_CFG_STQ1_THR_MAX_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_CFG_STQ1_THR_MAX_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_WOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010838;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_WOF(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010838;
#endif
    return fapi2::getScom(i_target, INT_CQ_WOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_WOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010838));
#endif
    return fapi2::putScom(i_target, INT_CQ_WOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_WOF_INT_CQ_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010838));
#endif
    return o_data.insertFromRight<INT_CQ_WOF_INT_CQ_WOF,
           INT_CQ_WOF_INT_CQ_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_WOF_INT_CQ_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_WOF_INT_CQ_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010838));
#endif
    return o_data.insertFromRight<INT_CQ_WOF_INT_CQ_WOF,
           INT_CQ_WOF_INT_CQ_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_WOF_INT_CQ_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_WOF_INT_CQ_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010838));
#endif
    return i_data.extractToRight<INT_CQ_WOF_INT_CQ_WOF,
           INT_CQ_WOF_INT_CQ_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_WOF_INT_CQ_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a98;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a98;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_LCL_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_RMT_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_NCKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_RMT_CHKO_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_LCL_VC_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LOCAL_GROUP_SCAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_NRQ_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_LD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_GROUP_SCAN_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_VICTIM_IS_FIRST_USABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_CNT_HOLD_P1_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a98));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_1_RESERVED_60_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH3_DATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010abf;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH3_DATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010abf;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH3_DATA3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010abf));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_AIB_RX_CRD_CMD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_AIB_RX_CRD_CMD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a11;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_AIB_RX_CRD_CMD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_AIB_RX_CRD_CMD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_AIB_RX_CRD_CMD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH0_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH3_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_CQ_CH7_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH1_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49,
           INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a11));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD,
           INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_CMD_PC_AIB_VC_CH2_MAX_CMD_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a32;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_DBG_INT_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_DBG_INT_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_DBG_INT_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_DBG_INT_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_DBG_INT_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_DBG_INT_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_DBG_INT_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_1_3,
           INT_PC_REGS_DBG_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_1_3,
           INT_PC_REGS_DBG_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_RESERVED_1_3,
           INT_PC_REGS_DBG_RESERVED_1_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_LEVEL,
           INT_PC_REGS_DBG_DBG_INT_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_LEVEL,
           INT_PC_REGS_DBG_DBG_INT_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_DBG_INT_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_DBG_INT_LEVEL,
           INT_PC_REGS_DBG_DBG_INT_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_THRDID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_THRDID,
           INT_PC_REGS_DBG_DBG_INT_THRDID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_DBG_INT_THRDID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_DBG_INT_THRDID,
           INT_PC_REGS_DBG_DBG_INT_THRDID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_DBG_INT_THRDID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_DBG_INT_THRDID,
           INT_PC_REGS_DBG_DBG_INT_THRDID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_DBG_INT_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_16_23,
           INT_PC_REGS_DBG_RESERVED_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_RESERVED_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_RESERVED_16_23,
           INT_PC_REGS_DBG_RESERVED_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_RESERVED_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a32));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_RESERVED_16_23,
           INT_PC_REGS_DBG_RESERVED_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR0_FATAL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR0_FATAL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac4;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR0_FATAL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR0_FATAL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010ac4));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR0_FATAL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac4));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR,
           INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac4));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR,
           INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac4));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR,
           INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_FATAL_INT_PC_ERR0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR1_CFG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR1_CFG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac9;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR1_CFG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR1_CFG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010ac9));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR1_CFG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac9));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0,
           INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac9));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0,
           INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac9));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0,
           INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_CFG1_INT_PC_ERR1_CFG1_ERROR_CONFIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR1_RECOV(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010acd;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR1_RECOV(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010acd;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR1_RECOV, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR1_RECOV(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010acd));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR1_RECOV, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010acd));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR,
           INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010acd));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR,
           INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010acd));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR,
           INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR1_RECOV_INT_PC_ERR1_RECOV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_EN0_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b03;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_EN0_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b03;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_EN0_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_EN0_RESET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010b03));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_EN0_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_DPS_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010949;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_DPS_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010949;
#endif
    return fapi2::getScom(i_target, INT_VC_DPS_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_DPS_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return fapi2::putScom(i_target, INT_VC_DPS_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_IPI_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_IPI_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_IPI_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_IPI_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_IPI_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_IPI_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_IPI_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_IPI_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_HWD_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_HWD_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_HWD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_HWD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_HWD_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_HWD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_HWD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HWD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NXC_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NXC_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_NXC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_NXC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_NXC_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_NXC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_NXC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NXC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_INT_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_INT_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_INT_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_INT_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_INT_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_INT_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_INT_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_INT_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_INT_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_INT_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_INT_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_INT_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_INT_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_OS_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_OS_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_OS_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_OS_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_OS_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_OS_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_OS_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_OS_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_OS_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_OS_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_OS_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_OS_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_OS_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_POOL_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_POOL_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_POOL_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_POOL_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_POOL_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_POOL_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_POOL_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_POOL_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_HARD_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_HARD_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_HARD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_HARD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_HARD_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_HARD_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_HARD_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_HARD_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_LOC_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_LOC_LOOKUP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_LOC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_LOC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_LOC_LOOKUP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_LOC_LOOKUP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_LOC_LOOKUP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_LOC_LOOKUP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_8_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_8_15,
           INT_VC_DPS_CFG_RESERVED_8_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_8_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_8_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_8_15,
           INT_VC_DPS_CFG_RESERVED_8_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_8_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_RESERVED_8_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_RESERVED_8_15,
           INT_VC_DPS_CFG_RESERVED_8_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_8_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_ESBC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_RESERVED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_RESERVED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT,
           INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_NB_EASC_SLOT_CREDIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_24_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_24_30,
           INT_VC_DPS_CFG_RESERVED_24_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_24_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_RESERVED_24_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_RESERVED_24_30,
           INT_VC_DPS_CFG_RESERVED_24_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_24_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_RESERVED_24_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_RESERVED_24_30,
           INT_VC_DPS_CFG_RESERVED_24_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_RESERVED_24_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_DPS_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_DPS_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_DPS_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.insertFromRight<INT_VC_DPS_CFG_DPS_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_DPS_CFG_DPS_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.setBit<INT_VC_DPS_CFG_DPS_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_DPS_CFG_DPS_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return o_data.clearBit<INT_VC_DPS_CFG_DPS_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_DPS_CFG_DPS_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.extractToRight<INT_VC_DPS_CFG_DPS_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_DPS_CFG_DPS_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010949));
#endif
    return i_data.getBit<INT_VC_DPS_CFG_DPS_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_DPS_CFG_DPS_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_ADDITIONAL_PERF_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201099d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_ADDITIONAL_PERF_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201099d;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_ADDITIONAL_PERF_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_ADDITIONAL_PERF_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_ADDITIONAL_PERF_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_FETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE,
           INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_MAX_OUTSTANDING_END_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63,
           INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63,
           INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099d));
#endif
    return i_data.extractToRight<INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63,
           INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_ADDITIONAL_PERF_2_RESERVED_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH0_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109a5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH0_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109a5;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH0_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH0_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109a5));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH0_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESBC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010959;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESBC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010959;
#endif
    return fapi2::getScom(i_target, INT_VC_ESBC_PERF_EVENT_SEL_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESBC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return fapi2::putScom(i_target, INT_VC_ESBC_PERF_EVENT_SEL_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES,
           INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_OO_MANY_PHB_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010959));
#endif
    return i_data.extractToRight<INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY,
           INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_PERF_EVENT_SEL_2_RIG_FROM_PHB_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010803;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010803;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010804;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010804;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010805;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010805;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010805, 0x3010804, 0x3010803));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c53;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c53;
#endif
    return fapi2::getScom(i_target, MM0_MM_CFG_NMMU_CTL_MISC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return fapi2::putScom(i_target, MM0_MM_CFG_NMMU_CTL_MISC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c53));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c4b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c4b;
#endif
    return fapi2::getScom(i_target, MM0_MM_CFG_NMMU_XLAT_CTL_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c4b));
#endif
    return fapi2::putScom(i_target, MM0_MM_CFG_NMMU_XLAT_CTL_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c4b));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c4b));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c4b));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c11;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c11));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c53;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c53;
#endif
    return fapi2::getScom(i_target, MM1_MM_CFG_NMMU_CTL_MISC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return fapi2::putScom(i_target, MM1_MM_CFG_NMMU_CTL_MISC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CTL_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.setBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.clearBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.getBit<MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c53));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c22;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c22;
#endif
    return fapi2::getScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return fapi2::putScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return o_data.setBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return o_data.clearBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c22));
#endif
    return i_data.getBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ERR_RPT_0_NX_PBI_WRITE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_10_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_10_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114b;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_10_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_10_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201114b));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_10_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114b));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION,
           NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114b));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION,
           NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114b));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION,
           NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_10_HASH_FUNCTION_REG_ADDRESS_10_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_7_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011148;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_7_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011148;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_7_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_7_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011148));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_7_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011148));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION,
           NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011148));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION,
           NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011148));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION,
           NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_7_HASH_FUNCTION_REG_ADDRESS_7_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_DATATAG_3_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_DATATAG_3_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114f;
#endif
    return fapi2::getScom(i_target, NX_CH4_DATATAG_3_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_DATATAG_3_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201114f));
#endif
    return fapi2::putScom(i_target, NX_CH4_DATATAG_3_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114f));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION,
           NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114f));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION,
           NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114f));
#endif
    return i_data.extractToRight<NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION,
           NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_3_HASH_FUNCTION_REG_DATATAG_3_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_ERROR_REPORT_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011058;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_ERROR_REPORT_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011058;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_ERROR_REPORT_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_ERROR_REPORT_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011058));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_ERROR_REPORT_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011058));
#endif
    return o_data.insertFromRight<NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1,
           NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011058));
#endif
    return o_data.insertFromRight<NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1,
           NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011058));
#endif
    return i_data.extractToRight<NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1,
           NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_ERROR_REPORT_1_DMA_ERROR_REPORT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c0;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c0));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_BAR_EFT_HI_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cf;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cf;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.setBit<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return o_data.clearBit<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cf));
#endif
    return i_data.getBit<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_EVENT_SEL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x39a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_EVENT_SEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x39a;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_EVENT_SEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_EVENT_SEL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_EVENT_SEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_SEL7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_EAST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE,
           PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_WEST_BITWISE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_PBS_EVENT_PORT_SEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PBS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MC1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_MCD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39a));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_SEL_CNPMS_PE0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TRACE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011826;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011826;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TRACE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TRACE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_0L_SEL,
           PB_PTLSCOM10_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_0L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_0L_SEL,
           PB_PTLSCOM10_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TRACE_CFG_0L_SEL,
           PB_PTLSCOM10_TRACE_CFG_0L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_0R_SEL,
           PB_PTLSCOM10_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_0R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_0R_SEL,
           PB_PTLSCOM10_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TRACE_CFG_0R_SEL,
           PB_PTLSCOM10_TRACE_CFG_0R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_1L_SEL,
           PB_PTLSCOM10_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_1L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_1L_SEL,
           PB_PTLSCOM10_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TRACE_CFG_1L_SEL,
           PB_PTLSCOM10_TRACE_CFG_1L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_1R_SEL,
           PB_PTLSCOM10_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TRACE_CFG_1R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TRACE_CFG_1R_SEL,
           PB_PTLSCOM10_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011826));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TRACE_CFG_1R_SEL,
           PB_PTLSCOM10_TRACE_CFG_1R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011830;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011830;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_00_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011830));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_00_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011831;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011831;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011831));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011803;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011803;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x4;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x5;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_MASK_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x11011803));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101180c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101180c;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_RCMD_RATE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_RCMD_RATE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181c;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PMU1_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PMU1_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1201181c));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PMU1_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011806;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011806;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011806));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011806));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011806));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011806));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011807;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011807;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011807));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011807));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011807));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011807));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011808;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011808;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011808));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011808));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011808));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011808));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF,
           PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201180e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201180e;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_TL_LINK_DLY_0123_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1201180e));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_TL_LINK_DLY_0123_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011834;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011834;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_20_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011834));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_20_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011835;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011835;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_21_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011835));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_21_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011823;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011823;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PMU2_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011823));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PMU2_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011816;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011816;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PSAVE23_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PSAVE23_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011800;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011800;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x13011800));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011811;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011811;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011811));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240a;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HCA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT,
           PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT,
           PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT,
           PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_UPDATE_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE,
           PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE,
           PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE,
           PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_SAMPLE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_SAMPLE_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_UPPER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD,
           PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DYNAMIC_LOWER_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_G_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_DISABLE_VG_NOT_SYS_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE,
           PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE,
           PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE,
           PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK,
           PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK,
           PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240a));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK,
           PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONFIG_REG_VG_TIMER_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240b;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE,
           PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE,
           PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE,
           PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_START_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_ERRINJ_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL,
           PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_DEBUG_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240b));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CONTROL_REG_RESET_ERRRPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c8;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_OPER_HANG_DIV_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_RTY_DRP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_DRP_PRIORITY_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_RETRY_BACKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c8));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CFG_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010840;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010840;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010841;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010841;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010842;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010842;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010842, 0x8010841, 0x8010840));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801084c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801084c;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_RESERVED1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801084c));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_RESERVED1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011810;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011810;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011810));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE,
           PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011851;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011851;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011851));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011851));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011851));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011851));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
