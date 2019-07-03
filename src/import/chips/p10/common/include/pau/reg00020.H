/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00020.H $          */
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

#ifndef __PAU_REG00020_H_
#define __PAU_REG00020_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_MULTI_AFU_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_64K_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_2M_PG_DISABLE_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_OPENCAPI3_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG0_KILL_XLATE_TYPE_DIAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_ATSD_HYP3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_ATSD_HYP3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP3;
#endif
    return fapi2::getScom(i_target, XTS_ATSD_HYP3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_ATSD_HYP3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return fapi2::putScom(i_target, XTS_ATSD_HYP3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP3_MSRHV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP3_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP3_MSRHV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP3_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP3_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.setBit<XTS_ATSD_HYP3_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_ATSD_HYP3_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.clearBit<XTS_ATSD_HYP3_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP3_MSRHV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP3_MSRHV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_ATSD_HYP3_MSRHV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return i_data.getBit<XTS_ATSD_HYP3_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP3_LPARID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP3_LPARID,
           XTS_ATSD_HYP3_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP3_LPARID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP3_LPARID,
           XTS_ATSD_HYP3_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP3_LPARID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP3));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP3_LPARID,
           XTS_ATSD_HYP3_LPARID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP3_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_DEBUG0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_DEBUG0_CONFIG;
#endif
    return fapi2::getScom(i_target, XTS_REG_DEBUG0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return fapi2::putScom(i_target, XTS_REG_DEBUG0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD0,
           XTS_REG_DEBUG0_CONFIG_POD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD0,
           XTS_REG_DEBUG0_CONFIG_POD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD0,
           XTS_REG_DEBUG0_CONFIG_POD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD1,
           XTS_REG_DEBUG0_CONFIG_POD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD1,
           XTS_REG_DEBUG0_CONFIG_POD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD1,
           XTS_REG_DEBUG0_CONFIG_POD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD2,
           XTS_REG_DEBUG0_CONFIG_POD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD2,
           XTS_REG_DEBUG0_CONFIG_POD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD2,
           XTS_REG_DEBUG0_CONFIG_POD2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD3,
           XTS_REG_DEBUG0_CONFIG_POD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD3,
           XTS_REG_DEBUG0_CONFIG_POD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD3,
           XTS_REG_DEBUG0_CONFIG_POD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD4,
           XTS_REG_DEBUG0_CONFIG_POD4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD4,
           XTS_REG_DEBUG0_CONFIG_POD4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD4,
           XTS_REG_DEBUG0_CONFIG_POD4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD5,
           XTS_REG_DEBUG0_CONFIG_POD5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD5,
           XTS_REG_DEBUG0_CONFIG_POD5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD5,
           XTS_REG_DEBUG0_CONFIG_POD5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD6,
           XTS_REG_DEBUG0_CONFIG_POD6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD6,
           XTS_REG_DEBUG0_CONFIG_POD6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD6,
           XTS_REG_DEBUG0_CONFIG_POD6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD7,
           XTS_REG_DEBUG0_CONFIG_POD7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD7,
           XTS_REG_DEBUG0_CONFIG_POD7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD7,
           XTS_REG_DEBUG0_CONFIG_POD7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD8,
           XTS_REG_DEBUG0_CONFIG_POD8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD8,
           XTS_REG_DEBUG0_CONFIG_POD8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD8,
           XTS_REG_DEBUG0_CONFIG_POD8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD9,
           XTS_REG_DEBUG0_CONFIG_POD9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD9,
           XTS_REG_DEBUG0_CONFIG_POD9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD9,
           XTS_REG_DEBUG0_CONFIG_POD9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD10,
           XTS_REG_DEBUG0_CONFIG_POD10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_POD10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_POD10,
           XTS_REG_DEBUG0_CONFIG_POD10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_POD10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_POD10,
           XTS_REG_DEBUG0_CONFIG_POD10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_POD10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_RESERVED1,
           XTS_REG_DEBUG0_CONFIG_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_RESERVED1,
           XTS_REG_DEBUG0_CONFIG_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_RESERVED1,
           XTS_REG_DEBUG0_CONFIG_RESERVED1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_ACT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.insertFromRight<XTS_REG_DEBUG0_CONFIG_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_DEBUG0_CONFIG_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.setBit<XTS_REG_DEBUG0_CONFIG_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_DEBUG0_CONFIG_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return o_data.clearBit<XTS_REG_DEBUG0_CONFIG_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_DEBUG0_CONFIG_ACT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.extractToRight<XTS_REG_DEBUG0_CONFIG_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_DEBUG0_CONFIG_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_DEBUG0_CONFIG));
#endif
    return i_data.getBit<XTS_REG_DEBUG0_CONFIG_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_DEBUG0_CONFIG_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
