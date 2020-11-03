/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00048.H $         */
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

#ifndef __PROC_REG00048_H_
#define __PROC_REG00048_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CMD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CMD;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CMD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CMD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CMD));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CMD_OCB_OCI_ADC_CMD_HWCTRL_START_SAMPLING]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SST0B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST0B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST0B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST0B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SST0B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST0B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ONGOING_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_WRITE_WHILE_BRIDGE_BUSY_ERR_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_ST0B_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0B_FSM_ERR_0B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2_LINEAR_WINDOW_MASK]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2_SPARE0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0_PULL_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0,
           TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0,
           TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS0_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0,
           TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS0_OCB_OCI_OCCS0_OCC_SCRATCH_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0,
           TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0,
           TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR0_RW, TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0,
           TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR0_OCB_OCI_OITR0_INTERRUPT_TYPE_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_SPARE2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1_OCB_PIB_OCBDR1_DATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2_OCB_PIB_OCBESR2_ERROR_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW0]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_FW1]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_QME_ERROR_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_STOP_RECOVERY_NOTIFY_PRD]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_HB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WATCHDOG_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_HALTED]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_WRITE_PROTECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_24_25]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGMSRWE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_DB_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_IDC_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_PARITY_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_37_41]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_JTAGACC_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCB_OCI_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_UE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_ECC_CE]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405_OCI_MACHINECHECK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRAM_SPARE_DIRECT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SRT_OTHER_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_49_50]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE0_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE1_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE2_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_GPE3_OCISLV_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405ICU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_C405DCU_M_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_OCC_COMPLEX_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_SPARE_59_61]

//>> PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]

//>> PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2]


//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]

//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV2_SRAM_SRBV2_BOOT_VECTOR_WORD2]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
