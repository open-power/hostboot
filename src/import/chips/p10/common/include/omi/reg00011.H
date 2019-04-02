/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00011.H $          */
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

#ifndef __OMI_REG00011_H_
#define __OMI_REG00011_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e56;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e56;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLERRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLERRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_RESERVED,
           MC3_CHAN1_USTL_USTLERRPT_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRPT_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRPT_RESERVED,
           MC3_CHAN1_USTL_USTLERRPT_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRPT_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e56));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRPT_RESERVED,
           MC3_CHAN1_USTL_USTLERRPT_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4e;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4e));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e53;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e53;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFAILMASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e53));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFAILMASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIR_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e40;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e40;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIR_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIR_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e41;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e41;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIR_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIR_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e42;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e42;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIR_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIR_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_HALF_SPEED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_RESERVED_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_RESERVED_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_RESERVED_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_SPARE_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_SPARE_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIR_SPARE_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIR_SPARE_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e42, 0xc010e41, 0xc010e40));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e46;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e46;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e46));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e46));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e46));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e46));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e43;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e43;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e44;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e44;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e45;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e45;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e45, 0xc010e44, 0xc010e43));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e48;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e48;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLFIRWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e48));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLFIRWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e48));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e48));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e48));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4c;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLINJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLINJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE,
           MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE,
           MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE,
           MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_FIR_INJECT,
           MC3_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_FIR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_FIR_INJECT,
           MC3_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_FIR_INJECT,
           MC3_CHAN1_USTL_USTLINJ_FIR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_US_DATA,
           MC3_CHAN1_USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_US_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_US_DATA,
           MC3_CHAN1_USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_US_DATA,
           MC3_CHAN1_USTL_USTLINJ_US_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLINJ_DATA_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4c));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e51;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e51;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLLOLDROP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLLOLDROP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e51));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON,
           MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e52;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e52;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLLOLMASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLLOLMASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e52));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4f;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLMCHWFM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLMCHWFM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLMCHWFM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLMCHWFM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLMCHWFM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH,
           MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH,
           MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH,
           MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_FAIL_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE,
           MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE,
           MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE,
           MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_TSCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_TSCALE,
           MC3_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_TSCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_TSCALE,
           MC3_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_TSCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_TSCALE,
           MC3_CHAN1_USTL_USTLMCHWFM_TSCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_TSCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SCOM_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_SUB_CHANNEL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS,
           MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS,
           MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4f));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS,
           MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLMCHWFM_HWFM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e54;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e54;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLOCAPIERROR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLOCAPIERROR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e54));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_CHAN1_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_CHAN1_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e4a;
#endif
    return fapi2::getScom(i_target, MC3_CHAN1_USTL_USTLSTATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_CHAN1_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return fapi2::putScom(i_target, MC3_CHAN1_USTL_USTLSTATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP,
           MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP,
           MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP,
           MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.insertFromRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.setBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return o_data.clearBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.extractToRight<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e4a));
#endif
    return i_data.getBit<MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_CHAN1_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_CLKMON_MONM_CLKRATIO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010ff0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_CLKMON_MONM_CLKRATIO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010ff0;
#endif
    return fapi2::getScom(i_target, MC3_MISC_CLKMON_MONM_CLKRATIO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_CLKMON_MONM_CLKRATIO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return fapi2::putScom(i_target, MC3_MISC_CLKMON_MONM_CLKRATIO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO,
           MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO,
           MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return i_data.extractToRight<MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO,
           MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.setBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.clearBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return i_data.extractToRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return i_data.getBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG0_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.insertFromRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.setBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return o_data.clearBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return i_data.extractToRight<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010ff0));
#endif
    return i_data.getBit<MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_CLKMON_MONM_CLKRATIO_CFG1_SYNC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f29;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f29;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_AACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_AACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS,
           MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS,
           MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS,
           MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_ECCGEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL,
           MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL,
           MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f29));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL,
           MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AACR_CHANNEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f2a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f2a;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_AADR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f2a));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_AADR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA,
           MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA,
           MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA,
           MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f2b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f2b;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_AAER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f2b));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_AAER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC,
           MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC,
           MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f2b));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC,
           MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f94;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f94;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f94));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f94));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f94));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f94));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM0Q_DBG0_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f95;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f95;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f95));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f96;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f96;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f96));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f96));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f96));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f96));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f97;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f97;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_DEBUG_BUS_64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f97));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED,
           MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBG1_SCOM1Q_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe8;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG0Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG0Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44,
           MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe8));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe9;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG1Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG1Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_EVENT_TO_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_RESET_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_CFG_WAT_EXT_ARM_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe9));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG1Q_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fea;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fea;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG2Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG2Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_CFG_WAT_LOC_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fea));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63,
           MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG2Q_RESERVED_60_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010feb;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010feb;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG3Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_DBGCFG3Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_LOC_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT2_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_GLOB_EVENT3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_RESERVED_31_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_MNT_GO_IDLE_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_ACT_FRC_TB_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_CNT_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010feb));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE,
           MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_DBGCFG3Q_CFG_WAT_TMR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe7;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBERRPTQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBERRPTQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AADR_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_AAER_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCBCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATCNTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA4_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA5_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA6_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA7_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA8_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCWATDATA9_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBCFGQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fe0;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBCFGQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBCFGQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBCFGQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_SPEC_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fe0));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBCFGQ_CFG_ENABLE_HOST_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f06;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f06;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f06));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f06));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f06));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f06));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRACT0_MCBISTFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f03;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f03;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f04;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f04;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f05;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f05;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f05, 0xc010f04, 0xc010f03));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRMASK_MCBISTFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f00;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f00;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f01;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f01;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f02;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f02;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_WAT_DEBUG_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN0B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN1B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN2B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3A_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_CHAN3B_APPLICATION_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f02, 0xc010f01, 0xc010f00));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRQ_INTERNAL_SCOM_ERROR_CLONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f08;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f08;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f08));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f08));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f08));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f08));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF,
           MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBISTFIRWOF_MCBISTFIRWOF_FIR_WOF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCBPARMQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010faf;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010faf;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBPARMQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCBPARMQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCBPARMQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010faf));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCBPARMQ_MCBPARMQ_CFG_CLOCK_MONITOR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f98;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f98;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f98));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa4;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa4));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa4));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa4));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa4));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa5;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa5));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa5));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa5));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa5));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa6;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa6));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa6));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa6));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa6));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN2_MCEBUSEN2_EVENT_BUS_SELECTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa7;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCEBUSEN3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_NABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa7));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f99;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f99;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.setBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return o_data.clearBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f99));
#endif
    return i_data.getBit<MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9a;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9b;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9c;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9d;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9e;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9f;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa0;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa1;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA7, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA7, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa2;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa3;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_MCWATDATA9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f0f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f0f;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_SPARE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_SPARE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_SPARE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC3_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_SPARE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC3_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_SPARE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC3_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f80;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f80;
#endif
    return fapi2::getScom(i_target, MC3_MISC_MBA_SCOMFIR_WATCFG0AQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return fapi2::putScom(i_target, MC3_MISC_MBA_SCOMFIR_WATCFG0AQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return o_data.insertFromRight<MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return i_data.extractToRight<MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC3_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
