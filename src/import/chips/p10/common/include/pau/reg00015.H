/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00015.H $          */
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

#ifndef __PAU_REG00015_H_
#define __PAU_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_XSLOP_VLOG_RGS_EEI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_XSLOP_VLOG_RGS_EEI;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_EEI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_EEI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_EEI));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_ARY_RD_ADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_ARY_RD_ADDR_REG;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_ARY_RD_ADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_ARY_RD_ADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_ARY_RD_ADDR_REG));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_DEBUG0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_DEBUG0_CONFIG;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_DEBUG0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_DEBUG0_CONFIG));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_DEBUG0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_WRAP_ERR_MASK_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_WRAP_ERR_MASK_0;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_WRAP_ERR_MASK_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_0));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_WRAP_ERR_MASK_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_0));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_0));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_0));
#endif
    return i_data.extractToRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP11;
#endif
    return fapi2::getScom(i_target, XTS_ATSD_HYP11, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return fapi2::putScom(i_target, XTS_ATSD_HYP11, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.setBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.clearBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP11_MSRHV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return i_data.getBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_LPARID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_LPARID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP11_LPARID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP11));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ATRMISS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ATRMISS;
#endif
    return fapi2::getScom(i_target, XTS_REG_ATRMISS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return fapi2::putScom(i_target, XTS_REG_ATRMISS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_RETIRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_RETIRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_RETIRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_IRQENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_IRQENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_IRQENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_SECOND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_SECOND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_SECOND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ATRMISS));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
