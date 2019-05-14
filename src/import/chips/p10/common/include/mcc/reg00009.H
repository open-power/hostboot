/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00009.H $          */
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

#ifndef __MCC_REG00009_H_
#define __MCC_REG00009_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCAMOC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCAMOC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCAMOC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCAMOC;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCAMOC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCAMOC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCAMOC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
           ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
           ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
           ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT,
           ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT,
           ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT,
           ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47,
           ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47,
           ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCAMOC));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47,
           ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCWAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCWAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCWAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCWAT;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCWAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCWAT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCWAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL,
           ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL,
           ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL,
           ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_RESERVED8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_RESERVED8_9,
           ATCL_CL_CLSCOM_MCWAT_RESERVED8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_RESERVED8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_RESERVED8_9,
           ATCL_CL_CLSCOM_MCWAT_RESERVED8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_RESERVED8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_RESERVED8_9,
           ATCL_CL_CLSCOM_MCWAT_RESERVED8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL,
           ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL,
           ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL,
           ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL,
           ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK,
           ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK,
           ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK,
           ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLX_DEBUG_SUM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_EN_DEBUG_OR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_RESERVED59_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_RESERVED59_62,
           ATCL_CL_CLSCOM_MCWAT_RESERVED59_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED59_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_RESERVED59_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_RESERVED59_62,
           ATCL_CL_CLSCOM_MCWAT_RESERVED59_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED59_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_RESERVED59_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_RESERVED59_62,
           ATCL_CL_CLSCOM_MCWAT_RESERVED59_62_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_RESERVED59_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCWAT));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLSTATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLSTATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLSTATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLSTATUS;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLSTATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLSTATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLSTATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return i_data.extractToRight<DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_A_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return i_data.extractToRight<DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF,
           DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_SUBCH_B_FAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return i_data.extractToRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_A_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return o_data.insertFromRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLSTATUS));
#endif
    return i_data.extractToRight<DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS,
           DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLSTATUS_DL_LANE_WIDTH_B_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WDF_WDFCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WDFCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WDF_WDFCFG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WDFCFG;
#endif
    return fapi2::getScom(i_target, WDF_WDFCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WDF_WDFCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return fapi2::putScom(i_target, WDF_WDFCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_3_8_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_3_8_SPARE,
           WDF_WDFCFG_WDFCFG_3_8_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_3_8_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_3_8_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_3_8_SPARE,
           WDF_WDFCFG_WDFCFG_3_8_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_3_8_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_WDFCFG_3_8_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_WDFCFG_3_8_SPARE,
           WDF_WDFCFG_WDFCFG_3_8_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_3_8_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_10_11_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_10_11_SPARE,
           WDF_WDFCFG_WDFCFG_10_11_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_10_11_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_10_11_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_10_11_SPARE,
           WDF_WDFCFG_WDFCFG_10_11_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_10_11_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_WDFCFG_10_11_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_WDFCFG_10_11_SPARE,
           WDF_WDFCFG_WDFCFG_10_11_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_10_11_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW0_ERR_INJ,
           WDF_WDFCFG_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW0_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW0_ERR_INJ,
           WDF_WDFCFG_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_DW0_ERR_INJ,
           WDF_WDFCFG_DSTL_DW0_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW1_ERR_INJ,
           WDF_WDFCFG_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW1_ERR_INJ,
           WDF_WDFCFG_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_DW1_ERR_INJ,
           WDF_WDFCFG_DSTL_DW1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW2_ERR_INJ,
           WDF_WDFCFG_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW2_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW2_ERR_INJ,
           WDF_WDFCFG_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_DW2_ERR_INJ,
           WDF_WDFCFG_DSTL_DW2_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW3_ERR_INJ,
           WDF_WDFCFG_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_DW3_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_DW3_ERR_INJ,
           WDF_WDFCFG_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_DW3_ERR_INJ,
           WDF_WDFCFG_DSTL_DW3_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_ONE_SHOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_PERSISTANT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.setBit<WDF_WDFCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.clearBit<WDF_WDFCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_DSTL_PERSISTANT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.getBit<WDF_WDFCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_22_31_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_22_31_SPARE,
           WDF_WDFCFG_WDFCFG_22_31_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_22_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_WDFCFG_22_31_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_WDFCFG_22_31_SPARE,
           WDF_WDFCFG_WDFCFG_22_31_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_22_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_WDFCFG_22_31_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_WDFCFG_22_31_SPARE,
           WDF_WDFCFG_WDFCFG_22_31_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_WDFCFG_22_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return o_data.insertFromRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFCFG));
#endif
    return i_data.extractToRight<WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE,
           WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTCFG;
#endif
    return fapi2::getScom(i_target, WRITE_WRTCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return fapi2::putScom(i_target, WRITE_WRTCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_2_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_2_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_2_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW0_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW0_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW2_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW2_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_DW3_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_DSTL_DW3_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_DSTL_PERSISTANT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTCFG_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_22_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_22_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_22_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_WRT_WDF_ECC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRT_WDF_ECC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_WRT_WDF_ECC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRT_WDF_ECC;
#endif
    return fapi2::getScom(i_target, WRITE_WRT_WDF_ECC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_WRT_WDF_ECC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return fapi2::putScom(i_target, WRITE_WRT_WDF_ECC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_0_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_0_ERR_TYPE,
           WRITE_WRT_WDF_ECC_0_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_0_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_0_ERR_TYPE,
           WRITE_WRT_WDF_ECC_0_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_0_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_0_ERR_TYPE,
           WRITE_WRT_WDF_ECC_0_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_0_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_0_SYNDROME,
           WRITE_WRT_WDF_ECC_0_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_0_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_0_SYNDROME,
           WRITE_WRT_WDF_ECC_0_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_0_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_0_SYNDROME,
           WRITE_WRT_WDF_ECC_0_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_1_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_1_ERR_TYPE,
           WRITE_WRT_WDF_ECC_1_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_1_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_1_ERR_TYPE,
           WRITE_WRT_WDF_ECC_1_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_1_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_1_ERR_TYPE,
           WRITE_WRT_WDF_ECC_1_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_1_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_1_SYNDROME,
           WRITE_WRT_WDF_ECC_1_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_1_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_1_SYNDROME,
           WRITE_WRT_WDF_ECC_1_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_1_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_1_SYNDROME,
           WRITE_WRT_WDF_ECC_1_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_2_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_2_ERR_TYPE,
           WRITE_WRT_WDF_ECC_2_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_2_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_2_ERR_TYPE,
           WRITE_WRT_WDF_ECC_2_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_2_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_2_ERR_TYPE,
           WRITE_WRT_WDF_ECC_2_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_2_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_2_SYNDROME,
           WRITE_WRT_WDF_ECC_2_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_2_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_2_SYNDROME,
           WRITE_WRT_WDF_ECC_2_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_2_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_2_SYNDROME,
           WRITE_WRT_WDF_ECC_2_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_3_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_3_ERR_TYPE,
           WRITE_WRT_WDF_ECC_3_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_3_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_3_ERR_TYPE,
           WRITE_WRT_WDF_ECC_3_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_3_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_3_ERR_TYPE,
           WRITE_WRT_WDF_ECC_3_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_3_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_3_SYNDROME,
           WRITE_WRT_WDF_ECC_3_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_WDF_ECC_3_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_WDF_ECC_3_SYNDROME,
           WRITE_WRT_WDF_ECC_3_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_WDF_ECC_3_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_WDF_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_WDF_ECC_3_SYNDROME,
           WRITE_WRT_WDF_ECC_3_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_WDF_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
