/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00015.H $          */
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

#ifndef __MCC_REG00015_H_
#define __MCC_REG00015_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c39;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c39;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCEBUSCL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCEBUSCL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC,
           ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c39));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f7f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f7f;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f7f));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f7f));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f7f));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f7f));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f76;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f76;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f76));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f76));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f76));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f76));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_SCOM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b40;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b40;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_SCOM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b41;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b41;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b42;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011b42;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011b42, 0xc011b41, 0xc011b40));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e11;
#endif
    return fapi2::getScom(i_target, USTL_USTLLOLDROP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return fapi2::putScom(i_target, USTL_USTLLOLDROP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_A_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return i_data.extractToRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_B_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e11));
#endif
    return i_data.extractToRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
