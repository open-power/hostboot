/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00001.H $           */
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

#ifndef __MC_REG00001_H_
#define __MC_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> PREP_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DBG_CBS_CC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DBG_CBS_CC]

//>> GET_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DBG_CBS_CC;
#endif
    return fapi2::getScom(i_target, DBG_CBS_CC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DBG_CBS_CC]

//>> PUT_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return fapi2::putScom(i_target, DBG_CBS_CC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DBG_CBS_CC]


//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> CLEAR_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_RESET_EP]

//>> GET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_RESET_EP]

//>> GET_[DBG_CBS_CC_DBG_RESET_EP]
static inline bool GET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> CLEAR_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_OPCG_IP]

//>> GET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> GET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline bool GET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> CLEAR_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline bool GET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> CLEAR_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> GET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> GET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline bool GET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> CLEAR_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CBS_REQ]

//>> GET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> GET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline bool GET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> SET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> GET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> SET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> SET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> GET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> CLEAR_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline bool GET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> GET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> GET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline bool GET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> GET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> GET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CC_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> CLEAR_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline bool GET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline bool GET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> CLEAR_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline bool GET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> CLEAR_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline bool GET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> CLEAR_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline bool GET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> PREP_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ADDR_TRAP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_PSC_ADDR_TRAP_REG]

//>> GET_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ADDR_TRAP_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_ADDR_TRAP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG]

//>> PUT_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_ADDR_TRAP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_PSC_ADDR_TRAP_REG]


//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> PREP_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_PSC_PSCOM_MODE_REG]

//>> GET_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_PSCOM_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG]

//>> PUT_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_PSCOM_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_PSC_PSCOM_MODE_REG]


//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> PREP_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HEARTBEAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HEARTBEAT_REG]

//>> GET_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HEARTBEAT_REG;
#endif
    return fapi2::getScom(i_target, HEARTBEAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HEARTBEAT_REG]

//>> PUT_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return fapi2::putScom(i_target, HEARTBEAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HEARTBEAT_REG]


//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.insertFromRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.insertFromRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.setBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> CLEAR_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.clearBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& GET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return i_data.extractToRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline bool GET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return i_data.getBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> PREP_[MBA_SCOMFIR_MCBERRPTQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCBERRPTQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MBA_SCOMFIR_MCBERRPTQ]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCBERRPTQ;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_MCBERRPTQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ]

//>> PUT_[MBA_SCOMFIR_MCBERRPTQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_MCBERRPTQ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_MCBERRPTQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MBA_SCOMFIR_MCBERRPTQ]


//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]
static inline bool GET_MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCBERRPTQ));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT]

//>> PREP_[MBA_SCOMFIR_MCEBUSEN0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCEBUSEN0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MBA_SCOMFIR_MCEBUSEN0]

//>> GET_[MBA_SCOMFIR_MCEBUSEN0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCEBUSEN0;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_MCEBUSEN0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MBA_SCOMFIR_MCEBUSEN0]

//>> PUT_[MBA_SCOMFIR_MCEBUSEN0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_MCEBUSEN0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCEBUSEN0));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_MCEBUSEN0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MBA_SCOMFIR_MCEBUSEN0]


//>> SET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCEBUSEN0));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]

//>> SET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCEBUSEN0));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]

//>> GET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCEBUSEN0));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS,
           MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS]

//>> PREP_[MBA_SCOMFIR_WATMSKB0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_WATMSKB0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_WATMSKB0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MBA_SCOMFIR_WATMSKB0]

//>> GET_[MBA_SCOMFIR_WATMSKB0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_WATMSKB0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_WATMSKB0;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_WATMSKB0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MBA_SCOMFIR_WATMSKB0]

//>> PUT_[MBA_SCOMFIR_WATMSKB0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_WATMSKB0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATMSKB0));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_WATMSKB0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MBA_SCOMFIR_WATMSKB0]


//>> SET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATMSKB0));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0,
           MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]

//>> SET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]
static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATMSKB0));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0,
           MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]

//>> GET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]
static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATMSKB0));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0,
           MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0]

//>> PREP_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_CAPT3]

//>> GET_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::getScom(i_target, OPCG_CAPT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_CAPT3]

//>> PUT_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return fapi2::putScom(i_target, OPCG_CAPT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_CAPT3]


//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> GET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> GET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> GET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> GET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> GET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> GET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> GET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> GET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> GET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> GET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> GET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> GET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12ODD]

//>> PREP_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_INTERRUPT_REG]

//>> GET_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, RECOV_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG]

//>> PUT_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, RECOV_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_INTERRUPT_REG]


//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.setBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> CLEAR_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.clearBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.extractToRight<RECOV_INTERRUPT_REG_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline bool GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.getBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]

//>> PREP_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN32(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN32]

//>> GET_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN32(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::getScom(i_target, SCAN32, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN32]

//>> PUT_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN32(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return fapi2::putScom(i_target, SCAN32, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN32]


//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> GET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return i_data.extractToRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN32_SCAN32_REG]

//>> PREP_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN64(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN64]

//>> GET_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN64(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::getScom(i_target, SCAN64, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN64]

//>> PUT_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN64(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return fapi2::putScom(i_target, SCAN64, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN64]


//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> GET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return i_data.extractToRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN64_SCAN64_REG]

//>> PREP_[SCOMFIR_MCTO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCTO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCTO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCTO]

//>> GET_[SCOMFIR_MCTO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCTO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCTO;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCTO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCTO]

//>> PUT_[SCOMFIR_MCTO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCTO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCTO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCTO]


//>> SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> CLEAR_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> GET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> GET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]
static inline bool GET_SCOMFIR_MCTO_SELECT_PB_HANG_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_SELECT_PB_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_PB_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_SELECT_PB_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> CLEAR_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> GET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> GET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]
static inline bool GET_SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE]

//>> SET_[SCOMFIR_MCTO_RPT_HANG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RPT_HANG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RPT_HANG_SELECT,
           SCOMFIR_MCTO_RPT_HANG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_RPT_HANG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RPT_HANG_SELECT]

//>> SET_[SCOMFIR_MCTO_RPT_HANG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RPT_HANG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RPT_HANG_SELECT,
           SCOMFIR_MCTO_RPT_HANG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_RPT_HANG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RPT_HANG_SELECT]

//>> GET_[SCOMFIR_MCTO_RPT_HANG_SELECT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_RPT_HANG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_RPT_HANG_SELECT,
           SCOMFIR_MCTO_RPT_HANG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_RPT_HANG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_RPT_HANG_SELECT]

//>> SET_[SCOMFIR_MCTO_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_4]

//>> SET_[SCOMFIR_MCTO_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_4]

//>> SET_[SCOMFIR_MCTO_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_4]

//>> CLEAR_[SCOMFIR_MCTO_RESERVED_4]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_RESERVED_4]

//>> GET_[SCOMFIR_MCTO_RESERVED_4]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_RESERVED_4]

//>> GET_[SCOMFIR_MCTO_RESERVED_4]
static inline bool GET_SCOMFIR_MCTO_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_RESERVED_4]

//>> SET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_CL_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_CL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_CL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]

//>> SET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_CL_TIMEOUT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_CL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_CL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]

//>> GET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_CL_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_CL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_CL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_CL_TIMEOUT_VALUE]

//>> SET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_LOCAL_HANG_COMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_LOCAL_HANG_COMP,
           SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_LOCAL_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]

//>> SET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_LOCAL_HANG_COMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_LOCAL_HANG_COMP,
           SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_LOCAL_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]

//>> GET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_LOCAL_HANG_COMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_LOCAL_HANG_COMP,
           SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_LOCAL_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_LOCAL_HANG_COMP]

//>> SET_[SCOMFIR_MCTO_HANG_COMP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_HANG_COMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_HANG_COMP,
           SCOMFIR_MCTO_HANG_COMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_HANG_COMP]

//>> SET_[SCOMFIR_MCTO_HANG_COMP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_HANG_COMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_HANG_COMP,
           SCOMFIR_MCTO_HANG_COMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_HANG_COMP]

//>> GET_[SCOMFIR_MCTO_HANG_COMP]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_HANG_COMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_HANG_COMP,
           SCOMFIR_MCTO_HANG_COMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_HANG_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_HANG_COMP]

//>> SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> CLEAR_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]
static inline bool GET_SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> CLEAR_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]
static inline bool GET_SCOMFIR_MCTO_ENABLE_CHANNEL_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_ENABLE_CHANNEL_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_CHANNEL_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_CHANNEL_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_APO_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_APO_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_APO_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_ENABLE_APO_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_ENABLE_APO_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_ENABLE_APO_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> CLEAR_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_ENABLE_APO_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_ENABLE_APO_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_ENABLE_APO_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_ENABLE_APO_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> GET_[SCOMFIR_MCTO_ENABLE_APO_HANG]
static inline bool GET_SCOMFIR_MCTO_ENABLE_APO_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_ENABLE_APO_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_ENABLE_APO_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_ENABLE_APO_HANG]

//>> SET_[SCOMFIR_MCTO_RESERVED_53]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RESERVED_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_53]

//>> SET_[SCOMFIR_MCTO_RESERVED_53]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_RESERVED_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_53]

//>> SET_[SCOMFIR_MCTO_RESERVED_53]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_RESERVED_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_RESERVED_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_RESERVED_53]

//>> CLEAR_[SCOMFIR_MCTO_RESERVED_53]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_RESERVED_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_RESERVED_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_RESERVED_53]

//>> GET_[SCOMFIR_MCTO_RESERVED_53]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_RESERVED_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_RESERVED_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_RESERVED_53]

//>> GET_[SCOMFIR_MCTO_RESERVED_53]
static inline bool GET_SCOMFIR_MCTO_RESERVED_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_RESERVED_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_RESERVED_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_RESERVED_53]

//>> SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.setBit<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> CLEAR_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.clearBit<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> GET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> GET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]
static inline bool GET_SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.getBit<SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG]

//>> SET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]

//>> SET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return o_data.insertFromRight<SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]

//>> GET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCTO));
#endif
    return i_data.extractToRight<SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE,
           SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE]

//>> PREP_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR0_TRACE_HI_DATA_REG]

//>> GET_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR0_TRACE_HI_DATA_REG]

//>> PUT_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR0_TRACE_HI_DATA_REG]


//>> SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA1_TR0_CONFIG_4]

//>> GET_[TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA1_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_4]

//>> PUT_[TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA1_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA1_TR0_CONFIG_4]


//>> SET_[TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_4_A,
           TRA1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_4_A]

//>> SET_[TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_4_A,
           TRA1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_4_A]

//>> GET_[TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_4_A,
           TRA1_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_4_A]

//>> SET_[TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_4_B,
           TRA1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_4_B]

//>> SET_[TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_4_B,
           TRA1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_4_B]

//>> GET_[TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_4_B,
           TRA1_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_4_B]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
