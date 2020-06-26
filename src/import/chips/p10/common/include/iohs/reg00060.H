/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00060.H $         */
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

#ifndef __IOHS_REG00060_H_
#define __IOHS_REG00060_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_CONFIG]

//>> GET_[DLP_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONFIG;
#endif
    return fapi2::getScom(i_target, DLP_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_CONFIG]

//>> PUT_[DLP_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return fapi2::putScom(i_target, DLP_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_CONFIG]


//>> SET_[DLP_CONFIG_LINK_PAIR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK_PAIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK_PAIR]

//>> SET_[DLP_CONFIG_LINK_PAIR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK_PAIR]

//>> SET_[DLP_CONFIG_LINK_PAIR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_LINK_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK_PAIR]

//>> CLEAR_[DLP_CONFIG_LINK_PAIR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_LINK_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_LINK_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_LINK_PAIR]

//>> GET_[DLP_CONFIG_LINK_PAIR]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_LINK_PAIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_LINK_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK_PAIR]

//>> GET_[DLP_CONFIG_LINK_PAIR]
static inline bool GET_DLP_CONFIG_LINK_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_LINK_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_LINK_PAIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK_PAIR]

//>> SET_[DLP_CONFIG_DISABLE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_SL_ECC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_DISABLE_SL_ECC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_SL_ECC]

//>> SET_[DLP_CONFIG_DISABLE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_SL_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_DISABLE_SL_ECC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_SL_ECC]

//>> SET_[DLP_CONFIG_DISABLE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_SL_ECC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_DISABLE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_SL_ECC]

//>> CLEAR_[DLP_CONFIG_DISABLE_SL_ECC]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_DISABLE_SL_ECC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_DISABLE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_DISABLE_SL_ECC]

//>> GET_[DLP_CONFIG_DISABLE_SL_ECC]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_DISABLE_SL_ECC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_DISABLE_SL_ECC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_DISABLE_SL_ECC]

//>> GET_[DLP_CONFIG_DISABLE_SL_ECC]
static inline bool GET_DLP_CONFIG_DISABLE_SL_ECC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_DISABLE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_DISABLE_SL_ECC]

//>> SET_[DLP_CONFIG_DISABLE_RECAL_START]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_RECAL_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_DISABLE_RECAL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_RECAL_START]

//>> SET_[DLP_CONFIG_DISABLE_RECAL_START]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_RECAL_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_DISABLE_RECAL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_RECAL_START]

//>> SET_[DLP_CONFIG_DISABLE_RECAL_START]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_DISABLE_RECAL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_DISABLE_RECAL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_DISABLE_RECAL_START]

//>> CLEAR_[DLP_CONFIG_DISABLE_RECAL_START]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_DISABLE_RECAL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_DISABLE_RECAL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_DISABLE_RECAL_START]

//>> GET_[DLP_CONFIG_DISABLE_RECAL_START]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_DISABLE_RECAL_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_DISABLE_RECAL_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_DISABLE_RECAL_START]

//>> GET_[DLP_CONFIG_DISABLE_RECAL_START]
static inline bool GET_DLP_CONFIG_DISABLE_RECAL_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_DISABLE_RECAL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_DISABLE_RECAL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_DISABLE_RECAL_START]

//>> SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SYN_CAPTURE_SL_ECC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_SYN_CAPTURE_SL_ECC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SYN_CAPTURE_SL_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_SYN_CAPTURE_SL_ECC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SYN_CAPTURE_SL_ECC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_SYN_CAPTURE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> CLEAR_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_SYN_CAPTURE_SL_ECC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_SYN_CAPTURE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> GET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_SYN_CAPTURE_SL_ECC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_SYN_CAPTURE_SL_ECC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> GET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]
static inline bool GET_DLP_CONFIG_SYN_CAPTURE_SL_ECC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_SYN_CAPTURE_SL_ECC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_SYN_CAPTURE_SL_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_SYN_CAPTURE_SL_ECC]

//>> SET_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SL_UE_CRC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_SL_UE_CRC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> SET_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SL_UE_CRC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_SL_UE_CRC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> SET_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_SL_UE_CRC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_SL_UE_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> CLEAR_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_SL_UE_CRC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_SL_UE_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> GET_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_SL_UE_CRC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_SL_UE_CRC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> GET_[DLP_CONFIG_SL_UE_CRC_ERR]
static inline bool GET_DLP_CONFIG_SL_UE_CRC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_SL_UE_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_SL_UE_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_SL_UE_CRC_ERR]

//>> SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_REPORT_SL_CHKBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_REPORT_SL_CHKBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_REPORT_SL_CHKBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> CLEAR_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_REPORT_SL_CHKBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> GET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_REPORT_SL_CHKBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> GET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]
static inline bool GET_DLP_CONFIG_REPORT_SL_CHKBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_REPORT_SL_CHKBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_REPORT_SL_CHKBIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_REPORT_SL_CHKBIT_ERR]

//>> SET_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_SAMPLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_BW_SAMPLE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> SET_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_SAMPLE_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_BW_SAMPLE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> SET_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_SAMPLE_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_BW_SAMPLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> CLEAR_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_BW_SAMPLE_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_BW_SAMPLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> GET_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_BW_SAMPLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_BW_SAMPLE_SIZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> GET_[DLP_CONFIG_BW_SAMPLE_SIZE]
static inline bool GET_DLP_CONFIG_BW_SAMPLE_SIZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_BW_SAMPLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_BW_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_BW_SAMPLE_SIZE]

//>> SET_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_BW_WINDOW_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> SET_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_BW_WINDOW_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> SET_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_BW_WINDOW_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_BW_WINDOW_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> CLEAR_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_BW_WINDOW_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_BW_WINDOW_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> GET_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_BW_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_BW_WINDOW_SIZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> GET_[DLP_CONFIG_BW_WINDOW_SIZE]
static inline bool GET_DLP_CONFIG_BW_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_BW_WINDOW_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_BW_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_BW_WINDOW_SIZE]

//>> SET_[DLP_CONFIG_PACKET_DELAY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_PACKET_DELAY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_PACKET_DELAY_LIMIT,
           DLP_CONFIG_PACKET_DELAY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_PACKET_DELAY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_PACKET_DELAY_LIMIT]

//>> SET_[DLP_CONFIG_PACKET_DELAY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_PACKET_DELAY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_PACKET_DELAY_LIMIT,
           DLP_CONFIG_PACKET_DELAY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_PACKET_DELAY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_PACKET_DELAY_LIMIT]

//>> GET_[DLP_CONFIG_PACKET_DELAY_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_PACKET_DELAY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_PACKET_DELAY_LIMIT,
           DLP_CONFIG_PACKET_DELAY_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_PACKET_DELAY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_PACKET_DELAY_LIMIT]

//>> SET_[DLP_CONFIG_TDM_DELAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TDM_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TDM_DELAY,
           DLP_CONFIG_TDM_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_TDM_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TDM_DELAY]

//>> SET_[DLP_CONFIG_TDM_DELAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TDM_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TDM_DELAY,
           DLP_CONFIG_TDM_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_TDM_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TDM_DELAY]

//>> GET_[DLP_CONFIG_TDM_DELAY]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_TDM_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_TDM_DELAY,
           DLP_CONFIG_TDM_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_TDM_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_TDM_DELAY]

//>> SET_[DLP_CONFIG_INBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_INBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_INBOUND_TOD_SELECT,
           DLP_CONFIG_INBOUND_TOD_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_INBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_INBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_INBOUND_TOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_INBOUND_TOD_SELECT,
           DLP_CONFIG_INBOUND_TOD_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_INBOUND_TOD_SELECT]

//>> GET_[DLP_CONFIG_INBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_INBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_INBOUND_TOD_SELECT,
           DLP_CONFIG_INBOUND_TOD_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_INBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_INBOUND_TOD_CROSS_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_INBOUND_TOD_CROSS_SELECT,
           DLP_CONFIG_INBOUND_TOD_CROSS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_CROSS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]

//>> SET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_INBOUND_TOD_CROSS_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_INBOUND_TOD_CROSS_SELECT,
           DLP_CONFIG_INBOUND_TOD_CROSS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_CROSS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]

//>> GET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_INBOUND_TOD_CROSS_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_INBOUND_TOD_CROSS_SELECT,
           DLP_CONFIG_INBOUND_TOD_CROSS_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_INBOUND_TOD_CROSS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_INBOUND_TOD_CROSS_SELECT]

//>> SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> CLEAR_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> GET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> GET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]
static inline bool GET_DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.setBit<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> CLEAR_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.clearBit<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> GET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> GET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]
static inline bool GET_DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.getBit<DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT]

//>> SET_[DLP_CONFIG_RECAL_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_RECAL_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_RECAL_TIMER,
           DLP_CONFIG_RECAL_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_RECAL_TIMER]

//>> SET_[DLP_CONFIG_RECAL_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_RECAL_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_RECAL_TIMER,
           DLP_CONFIG_RECAL_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_RECAL_TIMER]

//>> GET_[DLP_CONFIG_RECAL_TIMER]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_RECAL_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_RECAL_TIMER,
           DLP_CONFIG_RECAL_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_RECAL_TIMER]

//>> SET_[DLP_CONFIG_PSAVE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_PSAVE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_PSAVE_TIMEOUT,
           DLP_CONFIG_PSAVE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_PSAVE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_PSAVE_TIMEOUT]

//>> SET_[DLP_CONFIG_PSAVE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_PSAVE_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_PSAVE_TIMEOUT,
           DLP_CONFIG_PSAVE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_PSAVE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_PSAVE_TIMEOUT]

//>> GET_[DLP_CONFIG_PSAVE_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_PSAVE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_PSAVE_TIMEOUT,
           DLP_CONFIG_PSAVE_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_PSAVE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_PSAVE_TIMEOUT]

//>> SET_[DLP_CONFIG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TIMEOUT,
           DLP_CONFIG_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TIMEOUT]

//>> SET_[DLP_CONFIG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TIMEOUT,
           DLP_CONFIG_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TIMEOUT]

//>> GET_[DLP_CONFIG_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_TIMEOUT,
           DLP_CONFIG_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_TIMEOUT]

//>> SET_[DLP_CONFIG_TIMER_1US]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TIMER_1US(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TIMER_1US,
           DLP_CONFIG_TIMER_1US_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONFIG_TIMER_1US chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TIMER_1US]

//>> SET_[DLP_CONFIG_TIMER_1US]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONFIG_TIMER_1US(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return o_data.insertFromRight<DLP_CONFIG_TIMER_1US,
           DLP_CONFIG_TIMER_1US_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONFIG_TIMER_1US chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONFIG_TIMER_1US]

//>> GET_[DLP_CONFIG_TIMER_1US]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONFIG_TIMER_1US(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONFIG));
#endif
    return i_data.extractToRight<DLP_CONFIG_TIMER_1US,
           DLP_CONFIG_TIMER_1US_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONFIG_TIMER_1US chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONFIG_TIMER_1US]

//>> PREP_[DLP_LAT_MEASURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LAT_MEASURE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LAT_MEASURE]

//>> GET_[DLP_LAT_MEASURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LAT_MEASURE;
#endif
    return fapi2::getScom(i_target, DLP_LAT_MEASURE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LAT_MEASURE]

//>> PUT_[DLP_LAT_MEASURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return fapi2::putScom(i_target, DLP_LAT_MEASURE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LAT_MEASURE]


//>> SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> CLEAR_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]
static inline bool GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]

//>> SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]

//>> GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK0_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK0_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK0_ROUND_TRIP]

//>> SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> CLEAR_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]
static inline bool GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID]

//>> SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]

//>> SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]

//>> GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK1_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK1_ROUND_TRIP,
           DLP_LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK1_ROUND_TRIP]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> CLEAR_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]
static inline bool GET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> CLEAR_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]
static inline bool GET_DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]

//>> SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]

//>> GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> CLEAR_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]
static inline bool GET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.setBit<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> CLEAR_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.clearBit<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]
static inline bool GET_DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.getBit<DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]

//>> SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]

//>> GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE]

//>> SET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]

//>> SET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK0_TOD_LATENCY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK0_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]

//>> GET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK0_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK0_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK0_TOD_LATENCY]

//>> SET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]

//>> SET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& SET_DLP_LAT_MEASURE_LINK1_TOD_LATENCY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return o_data.insertFromRight<DLP_LAT_MEASURE_LINK1_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]

//>> GET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]
static inline fapi2::buffer<uint64_t>& GET_DLP_LAT_MEASURE_LINK1_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LAT_MEASURE));
#endif
    return i_data.extractToRight<DLP_LAT_MEASURE_LINK1_TOD_LATENCY,
           DLP_LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LAT_MEASURE_LINK1_TOD_LATENCY]

//>> PREP_[DLP_PHY_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_PHY_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_PHY_CONFIG]

//>> GET_[DLP_PHY_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_PHY_CONFIG;
#endif
    return fapi2::getScom(i_target, DLP_PHY_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_PHY_CONFIG]

//>> PUT_[DLP_PHY_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return fapi2::putScom(i_target, DLP_PHY_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_PHY_CONFIG]


//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]

//>> GET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]

//>> GET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ,
           DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_TIME,
           DLP_PHY_CONFIG_PHY_TRAIN_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_TIME,
           DLP_PHY_CONFIG_PHY_TRAIN_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]

//>> GET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PHY_TRAIN_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PHY_TRAIN_TIME,
           DLP_PHY_CONFIG_PHY_TRAIN_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PHY_TRAIN_TIME]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_A_HYST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_A_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_A_HYST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_A_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]

//>> GET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PHY_TRAIN_A_HYST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PHY_TRAIN_A_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PHY_TRAIN_A_HYST]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_B_HYST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_B_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]

//>> SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PHY_TRAIN_B_HYST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PHY_TRAIN_B_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]

//>> GET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PHY_TRAIN_B_HYST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PHY_TRAIN_B_HYST,
           DLP_PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PHY_TRAIN_B_HYST]

//>> SET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_PHASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_PHASE_SELECT,
           DLP_PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]

//>> SET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_PHASE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_PHASE_SELECT,
           DLP_PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]

//>> GET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PRBS_PHASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PRBS_PHASE_SELECT,
           DLP_PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS_PHASE_SELECT]

//>> SET_[DLP_PHY_CONFIG_PRBS_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_CONFIG,
           DLP_PHY_CONFIG_PRBS_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_CONFIG]

//>> SET_[DLP_PHY_CONFIG_PRBS_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_CONFIG,
           DLP_PHY_CONFIG_PRBS_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_CONFIG]

//>> GET_[DLP_PHY_CONFIG_PRBS_CONFIG]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PRBS_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PRBS_CONFIG,
           DLP_PHY_CONFIG_PRBS_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS_CONFIG]

//>> SET_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> SET_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> SET_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> CLEAR_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> GET_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PRBS_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> GET_[DLP_PHY_CONFIG_PRBS_INVERT]
static inline bool GET_DLP_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS_INVERT]

//>> SET_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_LINK0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> SET_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_LINK0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> SET_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> CLEAR_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> GET_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_LINK0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> GET_[DLP_PHY_CONFIG_LINK0_SELECT]
static inline bool GET_DLP_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_LINK0_SELECT]

//>> SET_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_LINK1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> SET_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_LINK1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> SET_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> CLEAR_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> GET_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_LINK1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> GET_[DLP_PHY_CONFIG_LINK1_SELECT]
static inline bool GET_DLP_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_LINK1_SELECT]

//>> SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS15_NPRBS7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS15_NPRBS7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS15_NPRBS7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRBS15_NPRBS7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRBS15_NPRBS7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_PRBS15_NPRBS7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> CLEAR_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_PRBS15_NPRBS7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_PRBS15_NPRBS7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> GET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PRBS15_NPRBS7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PRBS15_NPRBS7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> GET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]
static inline bool GET_DLP_PHY_CONFIG_PRBS15_NPRBS7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_PRBS15_NPRBS7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRBS15_NPRBS7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRBS15_NPRBS7]

//>> SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRECODER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRECODER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_PRECODER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> CLEAR_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> GET_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_PRECODER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> GET_[DLP_PHY_CONFIG_PRECODER_ENABLE]
static inline bool GET_DLP_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_PRECODER_ENABLE]

//>> SET_[DLP_PHY_CONFIG_50G_MODE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_50G_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_50G_MODE]

//>> SET_[DLP_PHY_CONFIG_50G_MODE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_50G_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_50G_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_50G_MODE]

//>> SET_[DLP_PHY_CONFIG_50G_MODE]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.setBit<DLP_PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_50G_MODE]

//>> CLEAR_[DLP_PHY_CONFIG_50G_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.clearBit<DLP_PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_PHY_CONFIG_50G_MODE]

//>> GET_[DLP_PHY_CONFIG_50G_MODE]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_50G_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_50G_MODE]

//>> GET_[DLP_PHY_CONFIG_50G_MODE]
static inline bool GET_DLP_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.getBit<DLP_PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_50G_MODE]

//>> SET_[DLP_PHY_CONFIG_DL_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_DL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_DL_SELECT,
           DLP_PHY_CONFIG_DL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_DL_SELECT]

//>> SET_[DLP_PHY_CONFIG_DL_SELECT]
static inline fapi2::buffer<uint64_t>& SET_DLP_PHY_CONFIG_DL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PHY_CONFIG_DL_SELECT,
           DLP_PHY_CONFIG_DL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_PHY_CONFIG_DL_SELECT]

//>> GET_[DLP_PHY_CONFIG_DL_SELECT]
static inline fapi2::buffer<uint64_t>& GET_DLP_PHY_CONFIG_DL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PHY_CONFIG));
#endif
    return i_data.extractToRight<DLP_PHY_CONFIG_DL_SELECT,
           DLP_PHY_CONFIG_DL_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_PHY_CONFIG_DL_SELECT]

//>> PREP_[DLP_LINK0_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_QUALITY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_QUALITY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK0_QUALITY]

//>> GET_[DLP_LINK0_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_QUALITY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_QUALITY;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_QUALITY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK0_QUALITY]

//>> PUT_[DLP_LINK0_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_QUALITY(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_QUALITY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK0_QUALITY]


//>> SET_[DLP_LINK0_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_TX_BW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_TX_BW,
           DLP_LINK0_QUALITY_TX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_TX_BW]

//>> SET_[DLP_LINK0_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_TX_BW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_TX_BW,
           DLP_LINK0_QUALITY_TX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_TX_BW]

//>> GET_[DLP_LINK0_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_QUALITY_TX_BW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK0_QUALITY_TX_BW,
           DLP_LINK0_QUALITY_TX_BW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_QUALITY_TX_BW]

//>> SET_[DLP_LINK0_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_RX_BW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_RX_BW,
           DLP_LINK0_QUALITY_RX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_RX_BW]

//>> SET_[DLP_LINK0_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_RX_BW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_RX_BW,
           DLP_LINK0_QUALITY_RX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_RX_BW]

//>> GET_[DLP_LINK0_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_QUALITY_RX_BW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK0_QUALITY_RX_BW,
           DLP_LINK0_QUALITY_RX_BW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_QUALITY_RX_BW]

//>> SET_[DLP_LINK0_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_ERROR_RATE,
           DLP_LINK0_QUALITY_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_ERROR_RATE]

//>> SET_[DLP_LINK0_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_ERROR_RATE,
           DLP_LINK0_QUALITY_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_ERROR_RATE]

//>> GET_[DLP_LINK0_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_QUALITY_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK0_QUALITY_ERROR_RATE,
           DLP_LINK0_QUALITY_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_QUALITY_ERROR_RATE]

//>> SET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]

//>> SET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]

//>> GET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3]

//>> SET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_SPARE_COUNTER_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_SPARE_COUNTER_2,
           DLP_LINK0_QUALITY_SPARE_COUNTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]

//>> SET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_QUALITY_SPARE_COUNTER_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK0_QUALITY_SPARE_COUNTER_2,
           DLP_LINK0_QUALITY_SPARE_COUNTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]

//>> GET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_QUALITY_SPARE_COUNTER_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK0_QUALITY_SPARE_COUNTER_2,
           DLP_LINK0_QUALITY_SPARE_COUNTER_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_QUALITY_SPARE_COUNTER_2]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
