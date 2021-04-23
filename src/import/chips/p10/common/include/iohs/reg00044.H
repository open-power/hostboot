/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00044.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __IOHS_REG00044_H_
#define __IOHS_REG00044_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_LINK0_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_TX_LANE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK0_TX_LANE_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_TX_LANE_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_TX_LANE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL]

//>> PUT_[DLP_LINK0_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_TX_LANE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK0_TX_LANE_CONTROL]


//>> SET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_00_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_00_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_00_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_00_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_01_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_01_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_01_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_01_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_02_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_02_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_02_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_02_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_03_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_03_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_03_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_03_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_04_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_04_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_04_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_04_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_05_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_05_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_05_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_05_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_06_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_06_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_06_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_06_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_07_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_07_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_07_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_07_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_FAILED,
           DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_TX_LANE_CONTROL_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_TX_LANE_CONTROL_FAILED,
           DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]

//>> GET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_TX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_TX_LANE_CONTROL_FAILED,
           DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_TX_LANE_CONTROL_FAILED]

//>> PREP_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]

//>> GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]

//>> PUT_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]


//>> SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>> SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>> GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>> PREP_[CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CONFIG]

//>> GET_[CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = CONFIG;
#endif
    return fapi2::getScom(i_target, CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CONFIG]

//>> PUT_[CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return fapi2::putScom(i_target, CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CONFIG]


//>> SET_[P10_20_CONFIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RESET]

//>> SET_[P10_20_CONFIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RESET]

//>> SET_[P10_20_CONFIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RESET]

//>> CLEAR_[P10_20_CONFIG_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_RESET]

//>> GET_[P10_20_CONFIG_RESET]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_RESET]

//>> GET_[P10_20_CONFIG_RESET]
static inline bool GET_P10_20_CONFIG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_RESET]

//>> SET_[P10_20_CONFIG_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RETRAIN]

//>> SET_[P10_20_CONFIG_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RETRAIN]

//>> SET_[P10_20_CONFIG_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_RETRAIN]

//>> CLEAR_[P10_20_CONFIG_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_RETRAIN]

//>> GET_[P10_20_CONFIG_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_RETRAIN]

//>> GET_[P10_20_CONFIG_RETRAIN]
static inline bool GET_P10_20_CONFIG_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_RETRAIN]

//>> SET_[P10_20_CONFIG_VERSION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_VERSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_VERSION,
           P10_20_CONFIG_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_VERSION]

//>> SET_[P10_20_CONFIG_VERSION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_VERSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_VERSION,
           P10_20_CONFIG_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_VERSION]

//>> GET_[P10_20_CONFIG_VERSION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_VERSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_VERSION,
           P10_20_CONFIG_VERSION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_VERSION]

//>> SET_[P10_20_CONFIG_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TRAIN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TRAIN_MODE,
           P10_20_CONFIG_TRAIN_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TRAIN_MODE]

//>> SET_[P10_20_CONFIG_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TRAIN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TRAIN_MODE,
           P10_20_CONFIG_TRAIN_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TRAIN_MODE]

//>> GET_[P10_20_CONFIG_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TRAIN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TRAIN_MODE,
           P10_20_CONFIG_TRAIN_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TRAIN_MODE]

//>> SET_[P10_20_CONFIG_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_SUPPORTED_MODES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_SUPPORTED_MODES,
           P10_20_CONFIG_SUPPORTED_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_SUPPORTED_MODES]

//>> SET_[P10_20_CONFIG_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_SUPPORTED_MODES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_SUPPORTED_MODES,
           P10_20_CONFIG_SUPPORTED_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_SUPPORTED_MODES]

//>> GET_[P10_20_CONFIG_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_SUPPORTED_MODES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_SUPPORTED_MODES,
           P10_20_CONFIG_SUPPORTED_MODES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_SUPPORTED_MODES]

//>> SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X4_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_X4_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X4_BACKOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_X4_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X4_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_X4_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> CLEAR_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_X4_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_X4_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> GET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_X4_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_X4_BACKOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> GET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]
static inline bool GET_P10_20_CONFIG_X4_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_X4_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_X4_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_X4_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X1_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_X1_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X1_BACKOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_X1_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_X1_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_X1_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> CLEAR_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_X1_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_X1_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> GET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_X1_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_X1_BACKOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> GET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]
static inline bool GET_P10_20_CONFIG_X1_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_X1_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_X1_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_X1_BACKOFF_ENABLE]

//>> SET_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_PWRMGT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> SET_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_PWRMGT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_PWRMGT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> SET_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> CLEAR_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> GET_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_PWRMGT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> GET_[P10_20_CONFIG_PWRMGT_ENABLE]
static inline bool GET_P10_20_CONFIG_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_PWRMGT_ENABLE]

//>> SET_[P10_20_CONFIG_TX_EP_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TX_EP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TX_EP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TX_EP_MODE]

//>> SET_[P10_20_CONFIG_TX_EP_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TX_EP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TX_EP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TX_EP_MODE]

//>> SET_[P10_20_CONFIG_TX_EP_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TX_EP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TX_EP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TX_EP_MODE]

//>> CLEAR_[P10_20_CONFIG_TX_EP_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TX_EP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TX_EP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TX_EP_MODE]

//>> GET_[P10_20_CONFIG_TX_EP_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TX_EP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TX_EP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TX_EP_MODE]

//>> GET_[P10_20_CONFIG_TX_EP_MODE]
static inline bool GET_P10_20_CONFIG_TX_EP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TX_EP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TX_EP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TX_EP_MODE]

//>> SET_[P10_20_CONFIG_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_PHY_CNTR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_PHY_CNTR_LIMIT,
           P10_20_CONFIG_PHY_CNTR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_PHY_CNTR_LIMIT]

//>> SET_[P10_20_CONFIG_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_PHY_CNTR_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_PHY_CNTR_LIMIT,
           P10_20_CONFIG_PHY_CNTR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_PHY_CNTR_LIMIT]

//>> GET_[P10_20_CONFIG_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_PHY_CNTR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_PHY_CNTR_LIMIT,
           P10_20_CONFIG_PHY_CNTR_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_PHY_CNTR_LIMIT]

//>> SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_128_130_ENCODING_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_128_130_ENCODING_ENABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_128_130_ENCODING_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> CLEAR_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> GET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_128_130_ENCODING_ENABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> GET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]
static inline bool GET_P10_20_CONFIG_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_128_130_ENCODING_ENABLED]

//>> SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> CLEAR_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> GET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> GET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]
static inline bool GET_P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT]

//>> SET_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_CRC_TX_INJECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_CRC_TX_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> SET_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_CRC_TX_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_CRC_TX_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> SET_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_CRC_TX_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_CRC_TX_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> CLEAR_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_CRC_TX_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_CRC_TX_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> GET_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_CRC_TX_INJECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_CRC_TX_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> GET_[P10_20_CONFIG_CRC_TX_INJECTION]
static inline bool GET_P10_20_CONFIG_CRC_TX_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_CRC_TX_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_CRC_TX_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_CRC_TX_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_ECC_CE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_CE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_ECC_CE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> CLEAR_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> GET_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_ECC_CE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> GET_[P10_20_CONFIG_ECC_CE_INJECTION]
static inline bool GET_P10_20_CONFIG_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_ECC_CE_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_ECC_UE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_UE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_ECC_UE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> SET_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> CLEAR_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> GET_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_ECC_UE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> GET_[P10_20_CONFIG_ECC_UE_INJECTION]
static inline bool GET_P10_20_CONFIG_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_ECC_UE_INJECTION]

//>> SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> CLEAR_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> GET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> GET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]
static inline bool GET_P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> CLEAR_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> GET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> GET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]
static inline bool GET_P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT]

//>> SET_[P10_20_CONFIG_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DEBUG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DEBUG_ENABLE]

//>> SET_[P10_20_CONFIG_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DEBUG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DEBUG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DEBUG_ENABLE]

//>> SET_[P10_20_CONFIG_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DEBUG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DEBUG_ENABLE]

//>> CLEAR_[P10_20_CONFIG_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_DEBUG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_DEBUG_ENABLE]

//>> GET_[P10_20_CONFIG_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_DEBUG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DEBUG_ENABLE]

//>> GET_[P10_20_CONFIG_DEBUG_ENABLE]
static inline bool GET_P10_20_CONFIG_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DEBUG_ENABLE]

//>> SET_[P10_20_CONFIG_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DEBUG_SELECT,
           P10_20_CONFIG_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DEBUG_SELECT]

//>> SET_[P10_20_CONFIG_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_DEBUG_SELECT,
           P10_20_CONFIG_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_DEBUG_SELECT]

//>> GET_[P10_20_CONFIG_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_DEBUG_SELECT,
           P10_20_CONFIG_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_DEBUG_SELECT]

//>> SET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_REPLAY_RSVD_ENTRIES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_REPLAY_RSVD_ENTRIES,
           P10_20_CONFIG_REPLAY_RSVD_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]

//>> SET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_REPLAY_RSVD_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_REPLAY_RSVD_ENTRIES,
           P10_20_CONFIG_REPLAY_RSVD_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]

//>> GET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_REPLAY_RSVD_ENTRIES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_REPLAY_RSVD_ENTRIES,
           P10_20_CONFIG_REPLAY_RSVD_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_REPLAY_RSVD_ENTRIES]

//>> SET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_FWD_PROGRESS_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_FWD_PROGRESS_TIMER,
           P10_20_CONFIG_FWD_PROGRESS_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]

//>> SET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_FWD_PROGRESS_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_FWD_PROGRESS_TIMER,
           P10_20_CONFIG_FWD_PROGRESS_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]

//>> GET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_FWD_PROGRESS_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_FWD_PROGRESS_TIMER,
           P10_20_CONFIG_FWD_PROGRESS_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_FWD_PROGRESS_TIMER]

//>> SET_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_LINKDOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_LINKDOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_LINKDOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_LINKDOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_LINKDOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLERROR_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> CLEAR_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLERROR_LINKDOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLERROR_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> GET_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLERROR_LINKDOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLERROR_LINKDOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> GET_[P10_20_CONFIG_TLERROR_LINKDOWN]
static inline bool GET_P10_20_CONFIG_TLERROR_LINKDOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLERROR_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ILATRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_ILATRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> SET_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ILATRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_ILATRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> SET_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ILATRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLERROR_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> CLEAR_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLERROR_ILATRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLERROR_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> GET_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLERROR_ILATRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLERROR_ILATRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> GET_[P10_20_CONFIG_TLERROR_ILATRIG]
static inline bool GET_P10_20_CONFIG_TLERROR_ILATRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLERROR_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_ILATRIG]

//>> SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_AFUFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_AFUFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_AFUFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_AFUFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_AFUFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLERROR_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> CLEAR_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLERROR_AFUFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLERROR_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> GET_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLERROR_AFUFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLERROR_AFUFREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> GET_[P10_20_CONFIG_TLERROR_AFUFREEZE]
static inline bool GET_P10_20_CONFIG_TLERROR_AFUFREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLERROR_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ALLFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_ALLFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ALLFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLERROR_ALLFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLERROR_ALLFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLERROR_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> CLEAR_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLERROR_ALLFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLERROR_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> GET_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLERROR_ALLFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLERROR_ALLFREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> GET_[P10_20_CONFIG_TLERROR_ALLFREEZE]
static inline bool GET_P10_20_CONFIG_TLERROR_ALLFREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLERROR_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLERROR_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLERROR_ALLFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_LINKDOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_LINKDOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_LINKDOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_LINKDOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_LINKDOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLEVENT_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> CLEAR_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLEVENT_LINKDOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLEVENT_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> GET_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLEVENT_LINKDOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLEVENT_LINKDOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> GET_[P10_20_CONFIG_TLEVENT_LINKDOWN]
static inline bool GET_P10_20_CONFIG_TLEVENT_LINKDOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLEVENT_LINKDOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_LINKDOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_LINKDOWN]

//>> SET_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ILATRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_ILATRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> SET_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ILATRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_ILATRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> SET_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ILATRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLEVENT_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> CLEAR_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLEVENT_ILATRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLEVENT_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> GET_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLEVENT_ILATRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLEVENT_ILATRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> GET_[P10_20_CONFIG_TLEVENT_ILATRIG]
static inline bool GET_P10_20_CONFIG_TLEVENT_ILATRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLEVENT_ILATRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ILATRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_ILATRIG]

//>> SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_AFUFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_AFUFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_AFUFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_AFUFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_AFUFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLEVENT_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> CLEAR_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLEVENT_AFUFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLEVENT_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> GET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLEVENT_AFUFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLEVENT_AFUFREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> GET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]
static inline bool GET_P10_20_CONFIG_TLEVENT_AFUFREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLEVENT_AFUFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_AFUFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_AFUFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ALLFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_ALLFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ALLFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_TLEVENT_ALLFREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_TLEVENT_ALLFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.setBit<P10_20_CONFIG_TLEVENT_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> CLEAR_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CONFIG_TLEVENT_ALLFREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.clearBit<P10_20_CONFIG_TLEVENT_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> GET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_TLEVENT_ALLFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_TLEVENT_ALLFREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> GET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]
static inline bool GET_P10_20_CONFIG_TLEVENT_ALLFREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.getBit<P10_20_CONFIG_TLEVENT_ALLFREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_CONFIG_TLEVENT_ALLFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_TLEVENT_ALLFREEZE]

//>> SET_[P10_20_CONFIG_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_CFG_SPARE,
           P10_20_CONFIG_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_CONFIG_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_CFG_SPARE]

//>> SET_[P10_20_CONFIG_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CONFIG_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return o_data.insertFromRight<P10_20_CONFIG_CFG_SPARE,
           P10_20_CONFIG_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_CONFIG_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CONFIG_CFG_SPARE]

//>> GET_[P10_20_CONFIG_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CONFIG_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CONFIG));
#endif
    return i_data.extractToRight<P10_20_CONFIG_CFG_SPARE,
           P10_20_CONFIG_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_CONFIG_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CONFIG_CFG_SPARE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
