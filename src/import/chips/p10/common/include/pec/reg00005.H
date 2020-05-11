/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pec/reg00005.H $          */
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

#ifndef __PEC_REG00005_H_
#define __PEC_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> PREP_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW]

//>> GET_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW]

//>> PUT_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW]

//>> PREP_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW_WAND]

//>> GET_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WAND;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW_WAND]

//>> PUT_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW_WAND]

//>> PREP_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW_WOR]

//>> GET_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WOR;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW_WOR]

//>> PUT_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW_WOR]


//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PCB_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_PCB_ACCESS]

//>> SET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PCB_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_PCB_ACCESS]

//>> GET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_PCB_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_PCB_ACCESS]

//>> PREP_[PB_PBCQ_PEPBREGS_NESTTRC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_NESTTRC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PBCQ_PEPBREGS_NESTTRC_REG]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_NESTTRC_REG;
#endif
    return fapi2::getScom(i_target, PB_PBCQ_PEPBREGS_NESTTRC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG]

//>> PUT_[PB_PBCQ_PEPBREGS_NESTTRC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return fapi2::putScom(i_target, PB_PBCQ_PEPBREGS_NESTTRC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PBCQ_PEPBREGS_NESTTRC_REG]


//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D,
           PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]
static inline bool GET_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_NESTTRC_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE]

//>> PREP_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_LONG_ROTATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN_LONG_ROTATE]

//>> GET_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_LONG_ROTATE;
#endif
    return fapi2::getScom(i_target, SCAN_LONG_ROTATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN_LONG_ROTATE]

//>> PUT_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN_LONG_ROTATE));
#endif
    return fapi2::putScom(i_target, SCAN_LONG_ROTATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN_LONG_ROTATE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
