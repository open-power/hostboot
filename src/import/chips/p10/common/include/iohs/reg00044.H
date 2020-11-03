/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00044.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
