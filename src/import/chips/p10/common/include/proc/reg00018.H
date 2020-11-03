/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00018.H $         */
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

#ifndef __PROC_REG00018_H_
#define __PROC_REG00018_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SST0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST0A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST0A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SST0A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ONGOING_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_WRITE_WHILE_BRIDGE_BUSY_ERR_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_ST0A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST0A_FSM_ERR_0A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1_LINEAR_WINDOW_MASK]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1_SPARE0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3_PULL_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3,
           TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3,
           TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS3_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3,
           TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS3_OCB_OCI_OCCS3_OCC_SCRATCH_3]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_SPARE2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2_OCB_PIB_OCBDR2_DATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1_OCB_PIB_OCBESR1_ERROR_ADDR]

//>> PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]

//>> PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1]


//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]

//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV1_SRAM_SRBV1_BOOT_VECTOR_WORD1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
