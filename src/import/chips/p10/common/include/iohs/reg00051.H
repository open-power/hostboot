/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00051.H $         */
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

#ifndef __IOHS_REG00051_H_
#define __IOHS_REG00051_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_STAT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_STAT0;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_STAT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_STAT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_STAT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_ABIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_ABIST_DONE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_ABIST_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_ABIST_DONE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_ABIST_DONE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_ABIST_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_ABIST_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_2I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_2I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_2I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_RESERVED_2I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_RESERVED_2I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_RESERVED_2I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_2I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_3I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_3I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_3I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_RESERVED_3I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_RESERVED_3I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_RESERVED_3I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_3I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_6I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_6I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_RESERVED_6I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_RESERVED_6I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_RESERVED_6I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_RESERVED_6I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_RESERVED_6I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_10I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_10I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_10I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_10I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_10I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_10I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_10I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_11I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_11I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_11I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_11I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_11I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_11I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_11I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_12I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_12I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_12I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_12I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_12I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_12I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_12I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_13I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_13I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_13I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_13I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_13I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_13I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_13I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_14I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_14I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_14I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_14I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_14I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_14I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_14I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_15I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_15I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_15I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_15I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_15I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_15I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_15I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_16I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_16I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_16I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_16I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_16I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_16I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_16I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_17I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_17I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_17I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_17I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_17I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_17I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_17I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_18I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_18I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_18I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_18I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_18I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_18I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_18I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_19I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_19I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_19I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_19I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_19I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_19I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_19I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_20I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_20I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_20I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_20I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_20I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_20I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_20I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_21I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_21I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_21I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_21I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_21I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_21I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_21I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_22I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_22I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_22I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_22I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_22I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_22I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_22I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_23I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_23I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_23I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_23I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_23I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_23I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_23I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_24I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_24I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_24I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_24I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_24I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_24I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_24I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_24I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_24I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_24I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_24I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_24I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_24I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_25I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_25I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_25I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_25I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_25I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_25I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_25I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_26I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_26I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_26I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_26I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_26I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_26I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_26I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_27I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_27I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_27I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_27I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_27I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_27I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_27I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_28I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_28I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_28I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_28I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_28I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_28I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_28I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_29I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_29I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_29I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_29I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_29I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_29I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_29I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_30I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_30I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_30I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_30I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_30I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_30I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_30I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_31I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_31I(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.insertFromRight<AXON_CPLT_STAT0_FREE_USAGE_31I,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.setBit<AXON_CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return o_data.clearBit<AXON_CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.extractToRight<AXON_CPLT_STAT0_FREE_USAGE_31I,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_STAT0_FREE_USAGE_31I(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_STAT0));
#endif
    return i_data.getBit<AXON_CPLT_STAT0_FREE_USAGE_31I>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_STAT0_FREE_USAGE_31I chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_LOCAL_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_LOCAL_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_ACTION0_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_HOSTATTN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_HOSTATTN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_HOSTATTN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_HOSTATTN;
#endif
    return fapi2::getScom(i_target, AXON_HOSTATTN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_HOSTATTN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return fapi2::putScom(i_target, AXON_HOSTATTN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_ANY_HOSTATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_ANY_HOSTATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_ANY_HOSTATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_ANY_HOSTATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_ANY_HOSTATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_ANY_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_ANY_HOSTATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_ANY_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_ANY_HOSTATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_ANY_HOSTATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_ANY_HOSTATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_ANY_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_ANY_HOSTATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED1H(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED1H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED1H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED1H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED1H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_RESERVED1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_RESERVED1H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_RESERVED1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_RESERVED1H(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_RESERVED1H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_RESERVED1H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_RESERVED1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED1H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED2H(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED2H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED2H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED2H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED2H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_RESERVED2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_RESERVED2H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_RESERVED2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_RESERVED2H(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_RESERVED2H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_RESERVED2H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_RESERVED2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED2H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED3H(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED3H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED3H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_RESERVED3H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_RESERVED3H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_RESERVED3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_RESERVED3H(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_RESERVED3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_RESERVED3H(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_RESERVED3H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_RESERVED3H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_RESERVED3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_RESERVED3H chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.insertFromRight<AXON_HOSTATTN_HOSTATTN_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_HOSTATTN_HOSTATTN_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.setBit<AXON_HOSTATTN_HOSTATTN_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_HOSTATTN_HOSTATTN_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return o_data.clearBit<AXON_HOSTATTN_HOSTATTN_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_HOSTATTN_HOSTATTN_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.extractToRight<AXON_HOSTATTN_HOSTATTN_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_HOSTATTN_HOSTATTN_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_HOSTATTN));
#endif
    return i_data.getBit<AXON_HOSTATTN_HOSTATTN_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_HOSTATTN_HOSTATTN_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_TRA0_TR0_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_TRA0_TR0_CONFIG_1;
#endif
    return fapi2::getScom(i_target, AXON_TRA0_TR0_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_TRA0_TR0_CONFIG_1));
#endif
    return fapi2::putScom(i_target, AXON_TRA0_TR0_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_TRA0_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_TRA0_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_TRA0_TR0_CONFIG_1));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_XSTOP3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_XSTOP3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_XSTOP3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_XSTOP3;
#endif
    return fapi2::getScom(i_target, AXON_XSTOP3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_XSTOP3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return fapi2::putScom(i_target, AXON_XSTOP3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_MASK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_MASK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_MASK_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_MASK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_MASK_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_MASK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_MASK_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_MASK_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_MASK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_ALIGNED_XSTOP3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_ALIGNED_XSTOP3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_ALIGNED_XSTOP3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_ALIGNED_XSTOP3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_ALIGNED_XSTOP3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_ALIGNED_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_ALIGNED_XSTOP3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_ALIGNED_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_ALIGNED_XSTOP3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_ALIGNED_XSTOP3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_ALIGNED_XSTOP3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_ALIGNED_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_ALIGNED_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.setBit<AXON_XSTOP3_XSTOP3_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP3_XSTOP3_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.clearBit<AXON_XSTOP3_XSTOP3_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP3_XSTOP3_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.getBit<AXON_XSTOP3_XSTOP3_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_WAIT_CYCLES,
           AXON_XSTOP3_XSTOP3_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP3_XSTOP3_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return o_data.insertFromRight<AXON_XSTOP3_XSTOP3_WAIT_CYCLES,
           AXON_XSTOP3_XSTOP3_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP3_XSTOP3_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP3));
#endif
    return i_data.extractToRight<AXON_XSTOP3_XSTOP3_WAIT_CYCLES,
           AXON_XSTOP3_XSTOP3_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP3_XSTOP3_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_STARTUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_STARTUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B,
           IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
