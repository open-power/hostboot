/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00014.H $          */
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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
