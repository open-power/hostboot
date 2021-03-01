/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00014.H $          */
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

#ifndef __OMI_REG00014_H_
#define __OMI_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[CYA_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CYA_BITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CYA_BITS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CYA_BITS]

//>> GET_[CYA_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CYA_BITS(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CYA_BITS;
#endif
    return fapi2::getScom(i_target, CYA_BITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CYA_BITS]

//>> PUT_[CYA_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CYA_BITS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return fapi2::putScom(i_target, CYA_BITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CYA_BITS]


//>> SET_[CYA_BITS_PRBS15_NPRBS7_0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PRBS15_NPRBS7_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_0]

//>> SET_[CYA_BITS_PRBS15_NPRBS7_0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PRBS15_NPRBS7_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_0]

//>> SET_[CYA_BITS_PRBS15_NPRBS7_0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PRBS15_NPRBS7_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_0]

//>> CLEAR_[CYA_BITS_PRBS15_NPRBS7_0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PRBS15_NPRBS7_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PRBS15_NPRBS7_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PRBS15_NPRBS7_0]

//>> GET_[CYA_BITS_PRBS15_NPRBS7_0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PRBS15_NPRBS7_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PRBS15_NPRBS7_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PRBS15_NPRBS7_0]

//>> GET_[CYA_BITS_PRBS15_NPRBS7_0]
static inline bool GET_CYA_BITS_PRBS15_NPRBS7_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PRBS15_NPRBS7_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PRBS15_NPRBS7_0]

//>> SET_[CYA_BITS_PRBS15_NPRBS7_1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PRBS15_NPRBS7_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_1]

//>> SET_[CYA_BITS_PRBS15_NPRBS7_1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PRBS15_NPRBS7_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_1]

//>> SET_[CYA_BITS_PRBS15_NPRBS7_1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PRBS15_NPRBS7_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PRBS15_NPRBS7_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PRBS15_NPRBS7_1]

//>> CLEAR_[CYA_BITS_PRBS15_NPRBS7_1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PRBS15_NPRBS7_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PRBS15_NPRBS7_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PRBS15_NPRBS7_1]

//>> GET_[CYA_BITS_PRBS15_NPRBS7_1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PRBS15_NPRBS7_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PRBS15_NPRBS7_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PRBS15_NPRBS7_1]

//>> GET_[CYA_BITS_PRBS15_NPRBS7_1]
static inline bool GET_CYA_BITS_PRBS15_NPRBS7_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PRBS15_NPRBS7_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PRBS15_NPRBS7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PRBS15_NPRBS7_1]

//>> SET_[CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD0,
           CYA_BITS_BITS0_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD0]

//>> SET_[CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD0,
           CYA_BITS_BITS0_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD0]

//>> GET_[CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS0_RSVD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS0_RSVD0,
           CYA_BITS_BITS0_RSVD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS0_RSVD0]

//>> SET_[CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD0,
           CYA_BITS_BITS1_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD0]

//>> SET_[CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD0,
           CYA_BITS_BITS1_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD0]

//>> GET_[CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS1_RSVD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS1_RSVD0,
           CYA_BITS_BITS1_RSVD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS1_RSVD0]

//>> SET_[P10_20_CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS0_RSVD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS0_RSVD0,
           P10_20_CYA_BITS_BITS0_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS0_RSVD0]

//>> SET_[P10_20_CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS0_RSVD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS0_RSVD0,
           P10_20_CYA_BITS_BITS0_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS0_RSVD0]

//>> GET_[P10_20_CYA_BITS_BITS0_RSVD0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_BITS0_RSVD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_BITS0_RSVD0,
           P10_20_CYA_BITS_BITS0_RSVD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_BITS0_RSVD0]

//>> SET_[P10_20_CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS1_RSVD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS1_RSVD0,
           P10_20_CYA_BITS_BITS1_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS1_RSVD0]

//>> SET_[P10_20_CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS1_RSVD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS1_RSVD0,
           P10_20_CYA_BITS_BITS1_RSVD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS1_RSVD0]

//>> GET_[P10_20_CYA_BITS_BITS1_RSVD0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_BITS1_RSVD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_BITS1_RSVD0,
           P10_20_CYA_BITS_BITS1_RSVD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_BITS1_RSVD0]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_DEAD_CYCLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_DEAD_CYCLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_DEAD_CYCLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> CLEAR_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_DEAD_CYCLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_DEAD_CYCLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_DEAD_CYCLE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_DEAD_CYCLE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]
static inline bool GET_P10_20_CYA_BITS_CS_DEAD_CYCLE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_DEAD_CYCLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE0]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_DEAD_CYCLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_DEAD_CYCLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_DEAD_CYCLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_DEAD_CYCLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> CLEAR_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_DEAD_CYCLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_DEAD_CYCLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_DEAD_CYCLE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_DEAD_CYCLE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]
static inline bool GET_P10_20_CYA_BITS_CS_DEAD_CYCLE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_DEAD_CYCLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_DEAD_CYCLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_DEAD_CYCLE1]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> CLEAR_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]
static inline bool GET_P10_20_CYA_BITS_CS_ALL_INIT_DONES0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES0]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> CLEAR_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_ALL_INIT_DONES1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]
static inline bool GET_P10_20_CYA_BITS_CS_ALL_INIT_DONES1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_ALL_INIT_DONES1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_ALL_INIT_DONES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_ALL_INIT_DONES1]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> CLEAR_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]
static inline bool GET_P10_20_CYA_BITS_CS_STS_REG_UPDATE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE0]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> CLEAR_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_STS_REG_UPDATE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]
static inline bool GET_P10_20_CYA_BITS_CS_STS_REG_UPDATE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_STS_REG_UPDATE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_STS_REG_UPDATE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_STS_REG_UPDATE1]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> CLEAR_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]
static inline bool GET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> CLEAR_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]
static inline bool GET_CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE0,
           CYA_BITS_RX_PN_SWAP_OVERRIDE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE0,
           CYA_BITS_RX_PN_SWAP_OVERRIDE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RX_PN_SWAP_OVERRIDE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RX_PN_SWAP_OVERRIDE0,
           CYA_BITS_RX_PN_SWAP_OVERRIDE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE0]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE1,
           CYA_BITS_RX_PN_SWAP_OVERRIDE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]

//>> SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RX_PN_SWAP_OVERRIDE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RX_PN_SWAP_OVERRIDE1,
           CYA_BITS_RX_PN_SWAP_OVERRIDE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]

//>> GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RX_PN_SWAP_OVERRIDE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RX_PN_SWAP_OVERRIDE1,
           CYA_BITS_RX_PN_SWAP_OVERRIDE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RX_PN_SWAP_OVERRIDE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RX_PN_SWAP_OVERRIDE1]

//>> SET_[CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD1,
           CYA_BITS_BITS0_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD1]

//>> SET_[CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD1,
           CYA_BITS_BITS0_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD1]

//>> GET_[CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS0_RSVD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS0_RSVD1,
           CYA_BITS_BITS0_RSVD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS0_RSVD1]

//>> SET_[CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD1,
           CYA_BITS_BITS1_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD1]

//>> SET_[CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD1,
           CYA_BITS_BITS1_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD1]

//>> GET_[CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS1_RSVD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS1_RSVD1,
           CYA_BITS_BITS1_RSVD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS1_RSVD1]

//>> SET_[P10_20_CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS0_RSVD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS0_RSVD1,
           P10_20_CYA_BITS_BITS0_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS0_RSVD1]

//>> SET_[P10_20_CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS0_RSVD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS0_RSVD1,
           P10_20_CYA_BITS_BITS0_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS0_RSVD1]

//>> GET_[P10_20_CYA_BITS_BITS0_RSVD1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_BITS0_RSVD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_BITS0_RSVD1,
           P10_20_CYA_BITS_BITS0_RSVD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_BITS0_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_BITS0_RSVD1]

//>> SET_[P10_20_CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS1_RSVD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS1_RSVD1,
           P10_20_CYA_BITS_BITS1_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS1_RSVD1]

//>> SET_[P10_20_CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_BITS1_RSVD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_BITS1_RSVD1,
           P10_20_CYA_BITS_BITS1_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_BITS1_RSVD1]

//>> GET_[P10_20_CYA_BITS_BITS1_RSVD1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_BITS1_RSVD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_BITS1_RSVD1,
           P10_20_CYA_BITS_BITS1_RSVD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_BITS1_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_BITS1_RSVD1]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW554143_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_0]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW554143_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_0]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_HW554143_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_0]

//>> CLEAR_[P10_20_CYA_BITS_CS_HW554143_0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_HW554143_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_HW554143_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_HW554143_0]

//>> GET_[P10_20_CYA_BITS_CS_HW554143_0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_HW554143_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_HW554143_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW554143_0]

//>> GET_[P10_20_CYA_BITS_CS_HW554143_0]
static inline bool GET_P10_20_CYA_BITS_CS_HW554143_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_HW554143_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW554143_0]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW554143_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_1]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW554143_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_1]

//>> SET_[P10_20_CYA_BITS_CS_HW554143_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW554143_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_HW554143_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW554143_1]

//>> CLEAR_[P10_20_CYA_BITS_CS_HW554143_1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_HW554143_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_HW554143_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_HW554143_1]

//>> GET_[P10_20_CYA_BITS_CS_HW554143_1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_HW554143_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_HW554143_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW554143_1]

//>> GET_[P10_20_CYA_BITS_CS_HW554143_1]
static inline bool GET_P10_20_CYA_BITS_CS_HW554143_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_HW554143_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW554143_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW554143_1]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW551927_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_0]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW551927_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_0]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_HW551927_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_0]

//>> CLEAR_[P10_20_CYA_BITS_CS_HW551927_0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_HW551927_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_HW551927_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_HW551927_0]

//>> GET_[P10_20_CYA_BITS_CS_HW551927_0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_HW551927_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_HW551927_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW551927_0]

//>> GET_[P10_20_CYA_BITS_CS_HW551927_0]
static inline bool GET_P10_20_CYA_BITS_CS_HW551927_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_HW551927_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW551927_0]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW551927_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_1]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_HW551927_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_1]

//>> SET_[P10_20_CYA_BITS_CS_HW551927_1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_HW551927_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_HW551927_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_HW551927_1]

//>> CLEAR_[P10_20_CYA_BITS_CS_HW551927_1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_HW551927_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_HW551927_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_HW551927_1]

//>> GET_[P10_20_CYA_BITS_CS_HW551927_1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_HW551927_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_HW551927_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW551927_1]

//>> GET_[P10_20_CYA_BITS_CS_HW551927_1]
static inline bool GET_P10_20_CYA_BITS_CS_HW551927_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_HW551927_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_HW551927_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_HW551927_1]

//>> SET_[P10_20_CYA_BITS_CS_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_EDPL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL0]

//>> SET_[P10_20_CYA_BITS_CS_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_EDPL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL0]

//>> SET_[P10_20_CYA_BITS_CS_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL0]

//>> CLEAR_[P10_20_CYA_BITS_CS_EDPL0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_EDPL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_EDPL0]

//>> GET_[P10_20_CYA_BITS_CS_EDPL0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_EDPL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_EDPL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_EDPL0]

//>> GET_[P10_20_CYA_BITS_CS_EDPL0]
static inline bool GET_P10_20_CYA_BITS_CS_EDPL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_EDPL0]

//>> SET_[P10_20_CYA_BITS_CS_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_EDPL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL1]

//>> SET_[P10_20_CYA_BITS_CS_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_CS_EDPL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL1]

//>> SET_[P10_20_CYA_BITS_CS_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_CS_EDPL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_CS_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_CS_EDPL1]

//>> CLEAR_[P10_20_CYA_BITS_CS_EDPL1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_CS_EDPL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_CS_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_CS_EDPL1]

//>> GET_[P10_20_CYA_BITS_CS_EDPL1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_CS_EDPL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_CS_EDPL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_EDPL1]

//>> GET_[P10_20_CYA_BITS_CS_EDPL1]
static inline bool GET_P10_20_CYA_BITS_CS_EDPL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_CS_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_CS_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_CS_EDPL1]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_RPB_READ_EN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_RPB_READ_EN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_RPB_READ_EN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> CLEAR_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_RPB_READ_EN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_RPB_READ_EN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> GET_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_RPB_READ_EN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_RPB_READ_EN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> GET_[P10_20_CYA_BITS_RPB_READ_EN0]
static inline bool GET_P10_20_CYA_BITS_RPB_READ_EN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_RPB_READ_EN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_RPB_READ_EN0]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_RPB_READ_EN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_RPB_READ_EN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> SET_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_RPB_READ_EN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_RPB_READ_EN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> CLEAR_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_RPB_READ_EN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_RPB_READ_EN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> GET_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_RPB_READ_EN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_RPB_READ_EN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> GET_[P10_20_CYA_BITS_RPB_READ_EN1]
static inline bool GET_P10_20_CYA_BITS_RPB_READ_EN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_RPB_READ_EN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_RPB_READ_EN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_RPB_READ_EN1]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_EARLY_RL_DETECT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_EARLY_RL_DETECT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_EARLY_RL_DETECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> CLEAR_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_EARLY_RL_DETECT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_EARLY_RL_DETECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> GET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_EARLY_RL_DETECT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_EARLY_RL_DETECT0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> GET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]
static inline bool GET_P10_20_CYA_BITS_EARLY_RL_DETECT0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_EARLY_RL_DETECT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_EARLY_RL_DETECT0]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_EARLY_RL_DETECT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<P10_20_CYA_BITS_EARLY_RL_DETECT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CYA_BITS_EARLY_RL_DETECT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<P10_20_CYA_BITS_EARLY_RL_DETECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> CLEAR_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CYA_BITS_EARLY_RL_DETECT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<P10_20_CYA_BITS_EARLY_RL_DETECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> GET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CYA_BITS_EARLY_RL_DETECT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<P10_20_CYA_BITS_EARLY_RL_DETECT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> GET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]
static inline bool GET_P10_20_CYA_BITS_EARLY_RL_DETECT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<P10_20_CYA_BITS_EARLY_RL_DETECT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access P10_20_CYA_BITS_EARLY_RL_DETECT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CYA_BITS_EARLY_RL_DETECT1]

//>> SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_TX_PSAVE_DELAY_TIMER0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_TX_PSAVE_DELAY_TIMER0,
           CYA_BITS_TX_PSAVE_DELAY_TIMER0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]

//>> SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_TX_PSAVE_DELAY_TIMER0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_TX_PSAVE_DELAY_TIMER0,
           CYA_BITS_TX_PSAVE_DELAY_TIMER0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]

//>> GET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_TX_PSAVE_DELAY_TIMER0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_TX_PSAVE_DELAY_TIMER0,
           CYA_BITS_TX_PSAVE_DELAY_TIMER0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_TX_PSAVE_DELAY_TIMER0]

//>> SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_TX_PSAVE_DELAY_TIMER1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_TX_PSAVE_DELAY_TIMER1,
           CYA_BITS_TX_PSAVE_DELAY_TIMER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]

//>> SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_TX_PSAVE_DELAY_TIMER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_TX_PSAVE_DELAY_TIMER1,
           CYA_BITS_TX_PSAVE_DELAY_TIMER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]

//>> GET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_TX_PSAVE_DELAY_TIMER1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_TX_PSAVE_DELAY_TIMER1,
           CYA_BITS_TX_PSAVE_DELAY_TIMER1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_TX_PSAVE_DELAY_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_TX_PSAVE_DELAY_TIMER1]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FAST_RETRAIN_DISABLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FAST_RETRAIN_DISABLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FAST_RETRAIN_DISABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> CLEAR_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FAST_RETRAIN_DISABLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FAST_RETRAIN_DISABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> GET_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FAST_RETRAIN_DISABLE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FAST_RETRAIN_DISABLE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> GET_[CYA_BITS_FAST_RETRAIN_DISABLE0]
static inline bool GET_CYA_BITS_FAST_RETRAIN_DISABLE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FAST_RETRAIN_DISABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FAST_RETRAIN_DISABLE0]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FAST_RETRAIN_DISABLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FAST_RETRAIN_DISABLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FAST_RETRAIN_DISABLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FAST_RETRAIN_DISABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> CLEAR_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FAST_RETRAIN_DISABLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FAST_RETRAIN_DISABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> GET_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FAST_RETRAIN_DISABLE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FAST_RETRAIN_DISABLE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> GET_[CYA_BITS_FAST_RETRAIN_DISABLE1]
static inline bool GET_CYA_BITS_FAST_RETRAIN_DISABLE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FAST_RETRAIN_DISABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FAST_RETRAIN_DISABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FAST_RETRAIN_DISABLE1]

//>> SET_[CYA_BITS_FLT_TRUNC_FIX]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FLT_TRUNC_FIX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FLT_TRUNC_FIX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FLT_TRUNC_FIX]

//>> SET_[CYA_BITS_FLT_TRUNC_FIX]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FLT_TRUNC_FIX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FLT_TRUNC_FIX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FLT_TRUNC_FIX]

//>> SET_[CYA_BITS_FLT_TRUNC_FIX]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FLT_TRUNC_FIX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FLT_TRUNC_FIX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FLT_TRUNC_FIX]

//>> CLEAR_[CYA_BITS_FLT_TRUNC_FIX]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FLT_TRUNC_FIX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FLT_TRUNC_FIX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FLT_TRUNC_FIX]

//>> GET_[CYA_BITS_FLT_TRUNC_FIX]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FLT_TRUNC_FIX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FLT_TRUNC_FIX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FLT_TRUNC_FIX]

//>> GET_[CYA_BITS_FLT_TRUNC_FIX]
static inline bool GET_CYA_BITS_FLT_TRUNC_FIX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FLT_TRUNC_FIX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FLT_TRUNC_FIX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FLT_TRUNC_FIX]

//>> SET_[CYA_BITS_BITS1_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD2]

//>> SET_[CYA_BITS_BITS1_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD2]

//>> SET_[CYA_BITS_BITS1_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_BITS1_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD2]

//>> CLEAR_[CYA_BITS_BITS1_RSVD2]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_BITS1_RSVD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_BITS1_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_BITS1_RSVD2]

//>> GET_[CYA_BITS_BITS1_RSVD2]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS1_RSVD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS1_RSVD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS1_RSVD2]

//>> GET_[CYA_BITS_BITS1_RSVD2]
static inline bool GET_CYA_BITS_BITS1_RSVD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_BITS1_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS1_RSVD2]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_KILL_CRC_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY0]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_KILL_CRC_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY0]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_KILL_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY0]

//>> CLEAR_[CYA_BITS_KILL_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_KILL_CRC_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_KILL_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_KILL_CRC_REPLAY0]

//>> GET_[CYA_BITS_KILL_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_KILL_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_KILL_CRC_REPLAY0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_KILL_CRC_REPLAY0]

//>> GET_[CYA_BITS_KILL_CRC_REPLAY0]
static inline bool GET_CYA_BITS_KILL_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_KILL_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_KILL_CRC_REPLAY0]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_KILL_CRC_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY1]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_KILL_CRC_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY1]

//>> SET_[CYA_BITS_KILL_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_KILL_CRC_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_KILL_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_KILL_CRC_REPLAY1]

//>> CLEAR_[CYA_BITS_KILL_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_KILL_CRC_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_KILL_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_KILL_CRC_REPLAY1]

//>> GET_[CYA_BITS_KILL_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_KILL_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_KILL_CRC_REPLAY1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_KILL_CRC_REPLAY1]

//>> GET_[CYA_BITS_KILL_CRC_REPLAY1]
static inline bool GET_CYA_BITS_KILL_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_KILL_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_KILL_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_KILL_CRC_REPLAY1]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> GET_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_REPLAY0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> GET_[CYA_BITS_RETRAIN_CRC_REPLAY0]
static inline bool GET_CYA_BITS_RETRAIN_CRC_REPLAY0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_REPLAY0]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> GET_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_REPLAY1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> GET_[CYA_BITS_RETRAIN_CRC_REPLAY1]
static inline bool GET_CYA_BITS_RETRAIN_CRC_REPLAY1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_REPLAY1]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_DISABLE_EDPL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL0]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_DISABLE_EDPL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL0]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_DISABLE_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL0]

//>> CLEAR_[CYA_BITS_PM_DISABLE_EDPL0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_DISABLE_EDPL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_DISABLE_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_DISABLE_EDPL0]

//>> GET_[CYA_BITS_PM_DISABLE_EDPL0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_DISABLE_EDPL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_DISABLE_EDPL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_DISABLE_EDPL0]

//>> GET_[CYA_BITS_PM_DISABLE_EDPL0]
static inline bool GET_CYA_BITS_PM_DISABLE_EDPL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_DISABLE_EDPL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_DISABLE_EDPL0]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_DISABLE_EDPL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL1]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_DISABLE_EDPL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL1]

//>> SET_[CYA_BITS_PM_DISABLE_EDPL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_DISABLE_EDPL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_DISABLE_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_DISABLE_EDPL1]

//>> CLEAR_[CYA_BITS_PM_DISABLE_EDPL1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_DISABLE_EDPL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_DISABLE_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_DISABLE_EDPL1]

//>> GET_[CYA_BITS_PM_DISABLE_EDPL1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_DISABLE_EDPL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_DISABLE_EDPL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_DISABLE_EDPL1]

//>> GET_[CYA_BITS_PM_DISABLE_EDPL1]
static inline bool GET_CYA_BITS_PM_DISABLE_EDPL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_DISABLE_EDPL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_DISABLE_EDPL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_DISABLE_EDPL1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> GET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_RETRAIN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> GET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]
static inline bool GET_CYA_BITS_RETRAIN_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RETRAIN0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> GET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_RETRAIN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> GET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]
static inline bool GET_CYA_BITS_RETRAIN_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RETRAIN1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> GET_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_RESET0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_RESET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> GET_[CYA_BITS_RETRAIN_CRC_RESET0]
static inline bool GET_CYA_BITS_RETRAIN_CRC_RESET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RESET0]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RETRAIN_CRC_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> SET_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RETRAIN_CRC_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RETRAIN_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> CLEAR_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RETRAIN_CRC_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RETRAIN_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> GET_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RETRAIN_CRC_RESET1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RETRAIN_CRC_RESET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> GET_[CYA_BITS_RETRAIN_CRC_RESET1]
static inline bool GET_CYA_BITS_RETRAIN_CRC_RESET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RETRAIN_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RETRAIN_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RETRAIN_CRC_RESET1]

//>> SET_[CYA_BITS_FRBUF_FULL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL0]

//>> SET_[CYA_BITS_FRBUF_FULL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL0]

//>> SET_[CYA_BITS_FRBUF_FULL0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FRBUF_FULL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL0]

//>> CLEAR_[CYA_BITS_FRBUF_FULL0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FRBUF_FULL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FRBUF_FULL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FRBUF_FULL0]

//>> GET_[CYA_BITS_FRBUF_FULL0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FRBUF_FULL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FRBUF_FULL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL0]

//>> GET_[CYA_BITS_FRBUF_FULL0]
static inline bool GET_CYA_BITS_FRBUF_FULL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FRBUF_FULL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL0]

//>> SET_[CYA_BITS_FRBUF_FULL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL1]

//>> SET_[CYA_BITS_FRBUF_FULL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL1]

//>> SET_[CYA_BITS_FRBUF_FULL1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FRBUF_FULL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL1]

//>> CLEAR_[CYA_BITS_FRBUF_FULL1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FRBUF_FULL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FRBUF_FULL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FRBUF_FULL1]

//>> GET_[CYA_BITS_FRBUF_FULL1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FRBUF_FULL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FRBUF_FULL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL1]

//>> GET_[CYA_BITS_FRBUF_FULL1]
static inline bool GET_CYA_BITS_FRBUF_FULL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FRBUF_FULL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL1]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL_REPLAY0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FRBUF_FULL_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> CLEAR_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FRBUF_FULL_REPLAY0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FRBUF_FULL_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> GET_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FRBUF_FULL_REPLAY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FRBUF_FULL_REPLAY0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> GET_[CYA_BITS_FRBUF_FULL_REPLAY0]
static inline bool GET_CYA_BITS_FRBUF_FULL_REPLAY0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FRBUF_FULL_REPLAY0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL_REPLAY0]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_FRBUF_FULL_REPLAY1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> SET_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_FRBUF_FULL_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_FRBUF_FULL_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> CLEAR_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_FRBUF_FULL_REPLAY1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_FRBUF_FULL_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> GET_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_FRBUF_FULL_REPLAY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_FRBUF_FULL_REPLAY1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> GET_[CYA_BITS_FRBUF_FULL_REPLAY1]
static inline bool GET_CYA_BITS_FRBUF_FULL_REPLAY1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_FRBUF_FULL_REPLAY1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_FRBUF_FULL_REPLAY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_FRBUF_FULL_REPLAY1]

//>> SET_[CYA_BITS_PM_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN0]

//>> SET_[CYA_BITS_PM_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN0]

//>> SET_[CYA_BITS_PM_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN0]

//>> CLEAR_[CYA_BITS_PM_RETRAIN0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_RETRAIN0]

//>> GET_[CYA_BITS_PM_RETRAIN0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_RETRAIN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RETRAIN0]

//>> GET_[CYA_BITS_PM_RETRAIN0]
static inline bool GET_CYA_BITS_PM_RETRAIN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RETRAIN0]

//>> SET_[CYA_BITS_PM_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN1]

//>> SET_[CYA_BITS_PM_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN1]

//>> SET_[CYA_BITS_PM_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RETRAIN1]

//>> CLEAR_[CYA_BITS_PM_RETRAIN1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_RETRAIN1]

//>> GET_[CYA_BITS_PM_RETRAIN1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_RETRAIN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RETRAIN1]

//>> GET_[CYA_BITS_PM_RETRAIN1]
static inline bool GET_CYA_BITS_PM_RETRAIN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RETRAIN1]

//>> SET_[CYA_BITS_PM_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET0]

//>> SET_[CYA_BITS_PM_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET0]

//>> SET_[CYA_BITS_PM_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET0]

//>> CLEAR_[CYA_BITS_PM_RESET0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_RESET0]

//>> GET_[CYA_BITS_PM_RESET0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_RESET0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_RESET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RESET0]

//>> GET_[CYA_BITS_PM_RESET0]
static inline bool GET_CYA_BITS_PM_RESET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RESET0]

//>> SET_[CYA_BITS_PM_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET1]

//>> SET_[CYA_BITS_PM_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_PM_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET1]

//>> SET_[CYA_BITS_PM_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_PM_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_PM_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_PM_RESET1]

//>> CLEAR_[CYA_BITS_PM_RESET1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_PM_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_PM_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_PM_RESET1]

//>> GET_[CYA_BITS_PM_RESET1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_PM_RESET1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_PM_RESET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RESET1]

//>> GET_[CYA_BITS_PM_RESET1]
static inline bool GET_CYA_BITS_PM_RESET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_PM_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_PM_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_PM_RESET1]

//>> SET_[CYA_BITS_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN0]

//>> SET_[CYA_BITS_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RETRAIN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN0]

//>> SET_[CYA_BITS_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN0]

//>> CLEAR_[CYA_BITS_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_CRC_RETRAIN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_CRC_RETRAIN0]

//>> GET_[CYA_BITS_CRC_RETRAIN0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_CRC_RETRAIN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RETRAIN0]

//>> GET_[CYA_BITS_CRC_RETRAIN0]
static inline bool GET_CYA_BITS_CRC_RETRAIN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_CRC_RETRAIN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RETRAIN0]

//>> SET_[CYA_BITS_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN1]

//>> SET_[CYA_BITS_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RETRAIN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN1]

//>> SET_[CYA_BITS_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RETRAIN1]

//>> CLEAR_[CYA_BITS_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_CRC_RETRAIN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_CRC_RETRAIN1]

//>> GET_[CYA_BITS_CRC_RETRAIN1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_CRC_RETRAIN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RETRAIN1]

//>> GET_[CYA_BITS_CRC_RETRAIN1]
static inline bool GET_CYA_BITS_CRC_RETRAIN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_CRC_RETRAIN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_CRC_RETRAIN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RETRAIN1]

//>> SET_[CYA_BITS_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET0]

//>> SET_[CYA_BITS_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET0]

//>> SET_[CYA_BITS_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET0]

//>> CLEAR_[CYA_BITS_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_CRC_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_CRC_RESET0]

//>> GET_[CYA_BITS_CRC_RESET0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_CRC_RESET0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_CRC_RESET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RESET0]

//>> GET_[CYA_BITS_CRC_RESET0]
static inline bool GET_CYA_BITS_CRC_RESET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_CRC_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_CRC_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RESET0]

//>> SET_[CYA_BITS_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET1]

//>> SET_[CYA_BITS_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_CRC_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET1]

//>> SET_[CYA_BITS_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_CRC_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_CRC_RESET1]

//>> CLEAR_[CYA_BITS_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_CRC_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_CRC_RESET1]

//>> GET_[CYA_BITS_CRC_RESET1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_CRC_RESET1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_CRC_RESET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RESET1]

//>> GET_[CYA_BITS_CRC_RESET1]
static inline bool GET_CYA_BITS_CRC_RESET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_CRC_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_CRC_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_CRC_RESET1]

//>> SET_[CYA_BITS_RP_NONZERO0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RP_NONZERO0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO0]

//>> SET_[CYA_BITS_RP_NONZERO0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RP_NONZERO0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO0]

//>> SET_[CYA_BITS_RP_NONZERO0]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RP_NONZERO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO0]

//>> CLEAR_[CYA_BITS_RP_NONZERO0]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RP_NONZERO0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RP_NONZERO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RP_NONZERO0]

//>> GET_[CYA_BITS_RP_NONZERO0]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RP_NONZERO0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RP_NONZERO0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RP_NONZERO0]

//>> GET_[CYA_BITS_RP_NONZERO0]
static inline bool GET_CYA_BITS_RP_NONZERO0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RP_NONZERO0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RP_NONZERO0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RP_NONZERO0]

//>> SET_[CYA_BITS_RP_NONZERO1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RP_NONZERO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO1]

//>> SET_[CYA_BITS_RP_NONZERO1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_RP_NONZERO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO1]

//>> SET_[CYA_BITS_RP_NONZERO1]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_RP_NONZERO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.setBit<CYA_BITS_RP_NONZERO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_RP_NONZERO1]

//>> CLEAR_[CYA_BITS_RP_NONZERO1]
static inline fapi2::buffer<uint64_t>& CLEAR_CYA_BITS_RP_NONZERO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.clearBit<CYA_BITS_RP_NONZERO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CYA_BITS_RP_NONZERO1]

//>> GET_[CYA_BITS_RP_NONZERO1]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_RP_NONZERO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_RP_NONZERO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RP_NONZERO1]

//>> GET_[CYA_BITS_RP_NONZERO1]
static inline bool GET_CYA_BITS_RP_NONZERO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.getBit<CYA_BITS_RP_NONZERO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CYA_BITS_RP_NONZERO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_RP_NONZERO1]

//>> SET_[CYA_BITS_BITS0_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD3,
           CYA_BITS_BITS0_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD3]

//>> SET_[CYA_BITS_BITS0_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS0_RSVD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS0_RSVD3,
           CYA_BITS_BITS0_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS0_RSVD3]

//>> GET_[CYA_BITS_BITS0_RSVD3]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS0_RSVD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS0_RSVD3,
           CYA_BITS_BITS0_RSVD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS0_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS0_RSVD3]

//>> SET_[CYA_BITS_BITS1_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD3,
           CYA_BITS_BITS1_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD3]

//>> SET_[CYA_BITS_BITS1_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_CYA_BITS_BITS1_RSVD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return o_data.insertFromRight<CYA_BITS_BITS1_RSVD3,
           CYA_BITS_BITS1_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CYA_BITS_BITS1_RSVD3]

//>> GET_[CYA_BITS_BITS1_RSVD3]
static inline fapi2::buffer<uint64_t>& GET_CYA_BITS_BITS1_RSVD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CYA_BITS));
#endif
    return i_data.extractToRight<CYA_BITS_BITS1_RSVD3,
           CYA_BITS_BITS1_RSVD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CYA_BITS_BITS1_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CYA_BITS_BITS1_RSVD3]

//>> PREP_[ERROR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_MASK]

//>> GET_[ERROR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_MASK(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_MASK;
#endif
    return fapi2::getScom(i_target, ERROR_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_MASK]

//>> PUT_[ERROR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_MASK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return fapi2::putScom(i_target, ERROR_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_MASK]


//>> SET_[ERROR_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_47]

//>> SET_[ERROR_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_47]

//>> SET_[ERROR_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_47]

//>> CLEAR_[ERROR_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_47]

//>> GET_[ERROR_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_47]

//>> GET_[ERROR_MASK_47]
static inline bool GET_ERROR_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_47]

//>> SET_[ERROR_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_46]

//>> SET_[ERROR_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_46]

//>> SET_[ERROR_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_46]

//>> CLEAR_[ERROR_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_46]

//>> GET_[ERROR_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_46]

//>> GET_[ERROR_MASK_46]
static inline bool GET_ERROR_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_46]

//>> SET_[ERROR_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_45]

//>> SET_[ERROR_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_45]

//>> SET_[ERROR_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_45]

//>> CLEAR_[ERROR_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_45]

//>> GET_[ERROR_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_45]

//>> GET_[ERROR_MASK_45]
static inline bool GET_ERROR_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_45]

//>> SET_[ERROR_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_44]

//>> SET_[ERROR_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_44]

//>> SET_[ERROR_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_44]

//>> CLEAR_[ERROR_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_44]

//>> GET_[ERROR_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_44]

//>> GET_[ERROR_MASK_44]
static inline bool GET_ERROR_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_44]

//>> SET_[ERROR_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_43]

//>> SET_[ERROR_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_43]

//>> SET_[ERROR_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_43]

//>> CLEAR_[ERROR_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_43]

//>> GET_[ERROR_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_43]

//>> GET_[ERROR_MASK_43]
static inline bool GET_ERROR_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_43]

//>> SET_[ERROR_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_42]

//>> SET_[ERROR_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_42]

//>> SET_[ERROR_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_42]

//>> CLEAR_[ERROR_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_42]

//>> GET_[ERROR_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_42]

//>> GET_[ERROR_MASK_42]
static inline bool GET_ERROR_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_42]

//>> SET_[ERROR_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_41]

//>> SET_[ERROR_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_41]

//>> SET_[ERROR_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_41]

//>> CLEAR_[ERROR_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_41]

//>> GET_[ERROR_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_41]

//>> GET_[ERROR_MASK_41]
static inline bool GET_ERROR_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_41]

//>> SET_[ERROR_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_40]

//>> SET_[ERROR_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_40]

//>> SET_[ERROR_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_40]

//>> CLEAR_[ERROR_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_40]

//>> GET_[ERROR_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_40]

//>> GET_[ERROR_MASK_40]
static inline bool GET_ERROR_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_40]

//>> SET_[ERROR_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_39]

//>> SET_[ERROR_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_39]

//>> SET_[ERROR_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_39]

//>> CLEAR_[ERROR_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_39]

//>> GET_[ERROR_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_39]

//>> GET_[ERROR_MASK_39]
static inline bool GET_ERROR_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_39]

//>> SET_[ERROR_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_38]

//>> SET_[ERROR_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_38]

//>> SET_[ERROR_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_38]

//>> CLEAR_[ERROR_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_38]

//>> GET_[ERROR_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_38]

//>> GET_[ERROR_MASK_38]
static inline bool GET_ERROR_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_38]

//>> SET_[ERROR_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_37]

//>> SET_[ERROR_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_37]

//>> SET_[ERROR_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_37]

//>> CLEAR_[ERROR_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_37]

//>> GET_[ERROR_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_37]

//>> GET_[ERROR_MASK_37]
static inline bool GET_ERROR_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_37]

//>> SET_[ERROR_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_36]

//>> SET_[ERROR_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_36]

//>> SET_[ERROR_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_36]

//>> CLEAR_[ERROR_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_36]

//>> GET_[ERROR_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_36]

//>> GET_[ERROR_MASK_36]
static inline bool GET_ERROR_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_36]

//>> SET_[ERROR_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_35]

//>> SET_[ERROR_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_35]

//>> SET_[ERROR_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_35]

//>> CLEAR_[ERROR_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_35]

//>> GET_[ERROR_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_35]

//>> GET_[ERROR_MASK_35]
static inline bool GET_ERROR_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_35]

//>> SET_[ERROR_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_34]

//>> SET_[ERROR_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_34]

//>> SET_[ERROR_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_34]

//>> CLEAR_[ERROR_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_34]

//>> GET_[ERROR_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_34]

//>> GET_[ERROR_MASK_34]
static inline bool GET_ERROR_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_34]

//>> SET_[ERROR_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_33]

//>> SET_[ERROR_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_33]

//>> SET_[ERROR_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_33]

//>> CLEAR_[ERROR_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_33]

//>> GET_[ERROR_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_33]

//>> GET_[ERROR_MASK_33]
static inline bool GET_ERROR_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_33]

//>> SET_[ERROR_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_32]

//>> SET_[ERROR_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_32]

//>> SET_[ERROR_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_32]

//>> CLEAR_[ERROR_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_32]

//>> GET_[ERROR_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_32]

//>> GET_[ERROR_MASK_32]
static inline bool GET_ERROR_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_32]

//>> SET_[ERROR_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_31]

//>> SET_[ERROR_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_31]

//>> SET_[ERROR_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_31]

//>> CLEAR_[ERROR_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_31]

//>> GET_[ERROR_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_31]

//>> GET_[ERROR_MASK_31]
static inline bool GET_ERROR_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_31]

//>> SET_[ERROR_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_30]

//>> SET_[ERROR_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_30]

//>> SET_[ERROR_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_30]

//>> CLEAR_[ERROR_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_30]

//>> GET_[ERROR_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_30]

//>> GET_[ERROR_MASK_30]
static inline bool GET_ERROR_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_30]

//>> SET_[ERROR_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_29]

//>> SET_[ERROR_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_29]

//>> SET_[ERROR_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_29]

//>> CLEAR_[ERROR_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_29]

//>> GET_[ERROR_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_29]

//>> GET_[ERROR_MASK_29]
static inline bool GET_ERROR_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_29]

//>> SET_[ERROR_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_28]

//>> SET_[ERROR_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_28]

//>> SET_[ERROR_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_28]

//>> CLEAR_[ERROR_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_28]

//>> GET_[ERROR_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_28]

//>> GET_[ERROR_MASK_28]
static inline bool GET_ERROR_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_28]

//>> SET_[ERROR_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_27]

//>> SET_[ERROR_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_27]

//>> SET_[ERROR_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_27]

//>> CLEAR_[ERROR_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_27]

//>> GET_[ERROR_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_27]

//>> GET_[ERROR_MASK_27]
static inline bool GET_ERROR_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_27]

//>> SET_[ERROR_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_26]

//>> SET_[ERROR_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_26]

//>> SET_[ERROR_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_26]

//>> CLEAR_[ERROR_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_26]

//>> GET_[ERROR_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_26]

//>> GET_[ERROR_MASK_26]
static inline bool GET_ERROR_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_26]

//>> SET_[ERROR_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_25]

//>> SET_[ERROR_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_25]

//>> SET_[ERROR_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_25]

//>> CLEAR_[ERROR_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_25]

//>> GET_[ERROR_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_25]

//>> GET_[ERROR_MASK_25]
static inline bool GET_ERROR_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_25]

//>> SET_[ERROR_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_24]

//>> SET_[ERROR_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_24]

//>> SET_[ERROR_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_24]

//>> CLEAR_[ERROR_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_24]

//>> GET_[ERROR_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_24]

//>> GET_[ERROR_MASK_24]
static inline bool GET_ERROR_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_24]

//>> SET_[ERROR_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_23]

//>> SET_[ERROR_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_23]

//>> SET_[ERROR_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_23]

//>> CLEAR_[ERROR_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_23]

//>> GET_[ERROR_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_23]

//>> GET_[ERROR_MASK_23]
static inline bool GET_ERROR_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_23]

//>> SET_[ERROR_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_22]

//>> SET_[ERROR_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_22]

//>> SET_[ERROR_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_22]

//>> CLEAR_[ERROR_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_22]

//>> GET_[ERROR_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_22]

//>> GET_[ERROR_MASK_22]
static inline bool GET_ERROR_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_22]

//>> SET_[ERROR_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_21]

//>> SET_[ERROR_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_21]

//>> SET_[ERROR_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_21]

//>> CLEAR_[ERROR_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_21]

//>> GET_[ERROR_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_21]

//>> GET_[ERROR_MASK_21]
static inline bool GET_ERROR_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_21]

//>> SET_[ERROR_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_20]

//>> SET_[ERROR_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_20]

//>> SET_[ERROR_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_20]

//>> CLEAR_[ERROR_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_20]

//>> GET_[ERROR_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_20]

//>> GET_[ERROR_MASK_20]
static inline bool GET_ERROR_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_20]

//>> SET_[ERROR_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_19]

//>> SET_[ERROR_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_19]

//>> SET_[ERROR_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_19]

//>> CLEAR_[ERROR_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_19]

//>> GET_[ERROR_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_19]

//>> GET_[ERROR_MASK_19]
static inline bool GET_ERROR_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_19]

//>> SET_[ERROR_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_18]

//>> SET_[ERROR_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_18]

//>> SET_[ERROR_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_18]

//>> CLEAR_[ERROR_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_18]

//>> GET_[ERROR_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_18]

//>> GET_[ERROR_MASK_18]
static inline bool GET_ERROR_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_18]

//>> SET_[ERROR_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_17]

//>> SET_[ERROR_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_17]

//>> SET_[ERROR_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_17]

//>> CLEAR_[ERROR_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_17]

//>> GET_[ERROR_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_17]

//>> GET_[ERROR_MASK_17]
static inline bool GET_ERROR_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_17]

//>> SET_[ERROR_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_16]

//>> SET_[ERROR_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_16]

//>> SET_[ERROR_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_16]

//>> CLEAR_[ERROR_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_16]

//>> GET_[ERROR_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_16]

//>> GET_[ERROR_MASK_16]
static inline bool GET_ERROR_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_16]

//>> SET_[ERROR_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_15]

//>> SET_[ERROR_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_15]

//>> SET_[ERROR_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_15]

//>> CLEAR_[ERROR_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_15]

//>> GET_[ERROR_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_15]

//>> GET_[ERROR_MASK_15]
static inline bool GET_ERROR_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_15]

//>> SET_[ERROR_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_14]

//>> SET_[ERROR_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_14]

//>> SET_[ERROR_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_14]

//>> CLEAR_[ERROR_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_14]

//>> GET_[ERROR_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_14]

//>> GET_[ERROR_MASK_14]
static inline bool GET_ERROR_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_14]

//>> SET_[ERROR_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_13]

//>> SET_[ERROR_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_13]

//>> SET_[ERROR_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_13]

//>> CLEAR_[ERROR_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_13]

//>> GET_[ERROR_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_13]

//>> GET_[ERROR_MASK_13]
static inline bool GET_ERROR_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_13]

//>> SET_[ERROR_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_12]

//>> SET_[ERROR_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_12]

//>> SET_[ERROR_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_12]

//>> CLEAR_[ERROR_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_12]

//>> GET_[ERROR_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_12]

//>> GET_[ERROR_MASK_12]
static inline bool GET_ERROR_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_12]

//>> SET_[ERROR_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_11]

//>> SET_[ERROR_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_11]

//>> SET_[ERROR_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_11]

//>> CLEAR_[ERROR_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_11]

//>> GET_[ERROR_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_11]

//>> GET_[ERROR_MASK_11]
static inline bool GET_ERROR_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_11]

//>> SET_[ERROR_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_10]

//>> SET_[ERROR_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_10]

//>> SET_[ERROR_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_10]

//>> CLEAR_[ERROR_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_10]

//>> GET_[ERROR_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_10]

//>> GET_[ERROR_MASK_10]
static inline bool GET_ERROR_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_10]

//>> SET_[ERROR_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_09]

//>> SET_[ERROR_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_09]

//>> SET_[ERROR_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_09]

//>> CLEAR_[ERROR_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_09]

//>> GET_[ERROR_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_09]

//>> GET_[ERROR_MASK_09]
static inline bool GET_ERROR_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_09]

//>> SET_[ERROR_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_08]

//>> SET_[ERROR_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_08]

//>> SET_[ERROR_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_08]

//>> CLEAR_[ERROR_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_08]

//>> GET_[ERROR_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_08]

//>> GET_[ERROR_MASK_08]
static inline bool GET_ERROR_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_08]

//>> SET_[ERROR_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_07]

//>> SET_[ERROR_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_07]

//>> SET_[ERROR_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_07]

//>> CLEAR_[ERROR_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_07]

//>> GET_[ERROR_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_07]

//>> GET_[ERROR_MASK_07]
static inline bool GET_ERROR_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_07]

//>> SET_[ERROR_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_06]

//>> SET_[ERROR_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_06]

//>> SET_[ERROR_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_06]

//>> CLEAR_[ERROR_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_06]

//>> GET_[ERROR_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_06]

//>> GET_[ERROR_MASK_06]
static inline bool GET_ERROR_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_06]

//>> SET_[ERROR_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_05]

//>> SET_[ERROR_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_05]

//>> SET_[ERROR_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_05]

//>> CLEAR_[ERROR_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_05]

//>> GET_[ERROR_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_05]

//>> GET_[ERROR_MASK_05]
static inline bool GET_ERROR_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_05]

//>> SET_[ERROR_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_04]

//>> SET_[ERROR_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_04]

//>> SET_[ERROR_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_04]

//>> CLEAR_[ERROR_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_04]

//>> GET_[ERROR_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_04]

//>> GET_[ERROR_MASK_04]
static inline bool GET_ERROR_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_04]

//>> SET_[ERROR_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_03]

//>> SET_[ERROR_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_03]

//>> SET_[ERROR_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_03]

//>> CLEAR_[ERROR_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_03]

//>> GET_[ERROR_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_03]

//>> GET_[ERROR_MASK_03]
static inline bool GET_ERROR_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_03]

//>> SET_[ERROR_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_02]

//>> SET_[ERROR_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_02]

//>> SET_[ERROR_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_02]

//>> CLEAR_[ERROR_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_02]

//>> GET_[ERROR_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_02]

//>> GET_[ERROR_MASK_02]
static inline bool GET_ERROR_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_02]

//>> SET_[ERROR_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_01]

//>> SET_[ERROR_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_01]

//>> SET_[ERROR_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_01]

//>> CLEAR_[ERROR_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_01]

//>> GET_[ERROR_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_01]

//>> GET_[ERROR_MASK_01]
static inline bool GET_ERROR_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_01]

//>> SET_[ERROR_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_00]

//>> SET_[ERROR_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.insertFromRight<ERROR_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_00]

//>> SET_[ERROR_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.setBit<ERROR_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_MASK_00]

//>> CLEAR_[ERROR_MASK_00]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return o_data.clearBit<ERROR_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_MASK_00]

//>> GET_[ERROR_MASK_00]
static inline fapi2::buffer<uint64_t>& GET_ERROR_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.extractToRight<ERROR_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_00]

//>> GET_[ERROR_MASK_00]
static inline bool GET_ERROR_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_MASK));
#endif
    return i_data.getBit<ERROR_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_MASK_00]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
