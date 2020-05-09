/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00018.H $         */
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

#ifndef __IOHS_REG00018_H_
#define __IOHS_REG00018_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]

//>> PUT_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL]


//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_DATA]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE]

//>> PREP_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]

//>> PUT_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL]


//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]
static inline bool GET_IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_1_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7]

//>> PREP_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]

//>> PUT_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL]


//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline bool GET_IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]

//>> PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL]


//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]

//>> PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL]


//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]

//>> PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL]


//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]
static inline bool GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]
static inline bool GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]
static inline bool GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]
static inline bool GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS]

//>> PREP_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> PREP_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]

//>> PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL]


//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2,
           IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> PREP_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]

//>> PUT_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL]


//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL]

//>> PREP_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]

//>> PUT_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL]


//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]
static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000]

//>> PREP_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]

//>> PUT_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL]


//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK1]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]

//>> SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]

//>> GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_RX_DAC_REGS_CNTL6_PL_PEAK2]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL3_PL_ZERO]

//>> PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL]

//>> PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_STROBE_CNT_MAX]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE,
           IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_CAPTURE_CYCLE]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_MODE9_PL_MARGIN]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]
static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR]

//>> PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE]

//>> PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_NS_EDGE]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL5_PL_EW_EDGE]

//>> PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]

//>> PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG]


//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>> PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]

//>> PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]


//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> PREP_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]

//>> GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]

//>> PUT_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG]


//>> SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> PREP_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]

//>> GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]

//>> PUT_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG]


//>> SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]

//>> PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL]


//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> PREP_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]

//>> PUT_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL]


//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
