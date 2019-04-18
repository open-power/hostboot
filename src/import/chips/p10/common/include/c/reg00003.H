/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00003.H $            */
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

#ifndef __C_REG00003_H_
#define __C_REG00003_H_

namespace scomt
{
namespace c
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL_SCOM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e28;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e28;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e2a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e2a;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e2b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0e2b;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0e2b, 0x200e0e2a, 0x200e0e28));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020482;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020482;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_OCC_SCOMC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_OCC_SCOMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20020482));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_OCC_SCOMC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020482));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC,
           EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020482));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC,
           EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020482));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC,
           EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_OCC_SCOMC_MODE_CX_OCC_SCOMC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V1_HMER_RWX_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020493;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V1_HMER_RWX_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020493;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V1_HMER_RWX_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V1_HMER_RWX_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V1_HMER_RWX_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V1_HMER_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002048f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V1_HMER_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002048f;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V1_HMER_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V1_HMER_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V1_HMER_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_CME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002048f, 0x20020493));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V1_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002044f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002044f;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RAM_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002044f));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RAM_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002044b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002044b;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RECOV_FWD_PROG_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002044b));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RECOV_FWD_PROG_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002041c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002041c;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_HID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_HID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002041c));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC000(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200204a3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC000(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200204a3;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC000, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC000(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC000, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC000_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC000_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC000_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC000_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC000_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC000_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC000_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC000_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC000_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC000_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC000_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC000_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC111(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200204a3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC111(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200204a3;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC111, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC111(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC111, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC111_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC111_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC111_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC111_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC111_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC111_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC111_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC111_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC111_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200204a3));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC111_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC111_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC111_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020a45;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020a45;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_2_A,
           EC_PC_TRACE1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_2_A,
           EC_PC_TRACE1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_CONFIG_2_A,
           EC_PC_TRACE1_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_2_B,
           EC_PC_TRACE1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_2_B,
           EC_PC_TRACE1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a45));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_CONFIG_2_B,
           EC_PC_TRACE1_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020a89;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020a89;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020a89));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002000e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2002000e;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2002000e));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_RD_EPS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020010;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_RD_EPS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020010;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_RD_EPS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_RD_EPS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_RD_EPS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020010));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE,
           L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020047;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20020047;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_4_A,
           L2TRA_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_4_A,
           L2TRA_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_4_A,
           L2TRA_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_4_B,
           L2TRA_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_4_B,
           L2TRA_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20020047));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_4_B,
           L2TRA_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_ERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010610;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_ERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010610;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_ERR_RPT0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_ERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_ERR_RPT0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR,
           L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR,
           L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR,
           L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010610));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_ERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010617;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_ERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010617;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_ERR_RPT1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_ERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_ERR_RPT1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010617));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2001060a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2001060a;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_MODE_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_MODE_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2001060a));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010685;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010685;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010685));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415,
           NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_PTRC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010686;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_PTRC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010686;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_PTRC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_PTRC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010686));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_PTRC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010643;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010643;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010644;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010644;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010645;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010645;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK,
           NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK,
           NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010645, 0x20010644, 0x20010643));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK,
           NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010653;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010653;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010653));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSCOM_ERROR_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010002;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSCOM_ERROR_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20010002;
#endif
    return fapi2::getScom(i_target, PSCOM_ERROR_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSCOM_ERROR_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return fapi2::putScom(i_target, PSCOM_ERROR_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_P0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_UL_P0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_P0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_UL_P0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_UL_P0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_UL_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_UL_P0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_UL_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_UL_P0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_UL_P0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_UL_P0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_UL_P0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_UL_P0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_GENERAL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_GENERAL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_GENERAL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_GENERAL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_GENERAL_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_GENERAL_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_GENERAL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_GENERAL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.insertFromRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.setBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return o_data.clearBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.extractToRight<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20010002));
#endif
    return i_data.getBit<PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CDBA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0800;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CDBA(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e0800;
#endif
    return fapi2::getScom(i_target, QME_CDBA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CDBA(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200e0800));
#endif
    return fapi2::putScom(i_target, QME_CDBA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_CDBA_QME_CDBA_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0800));
#endif
    return o_data.insertFromRight<QME_CDBA_QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_QME_CDBA_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBA_QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_CDBA_QME_CDBA_MESSAGE_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0800));
#endif
    return o_data.insertFromRight<QME_CDBA_QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_QME_CDBA_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBA_QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_CDBA_QME_CDBA_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e0800));
#endif
    return i_data.extractToRight<QME_CDBA_QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_QME_CDBA_MESSAGE_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBA_QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CSIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e087c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CSIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x200e087c;
#endif
    return fapi2::getScom(i_target, QME_CSIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CSIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x200e087c));
#endif
    return fapi2::putScom(i_target, QME_CSIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_CSIR_QME_CSIR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e087c));
#endif
    return o_data.insertFromRight<QME_CSIR_QME_CSIR_DATA,
           QME_CSIR_QME_CSIR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CSIR_QME_CSIR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_CSIR_QME_CSIR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e087c));
#endif
    return o_data.insertFromRight<QME_CSIR_QME_CSIR_DATA,
           QME_CSIR_QME_CSIR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CSIR_QME_CSIR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_CSIR_QME_CSIR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x200e087c));
#endif
    return i_data.extractToRight<QME_CSIR_QME_CSIR_DATA,
           QME_CSIR_QME_CSIR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CSIR_QME_CSIR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
