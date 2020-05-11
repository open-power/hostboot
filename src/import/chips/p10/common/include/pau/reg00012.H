/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00012.H $          */
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

#ifndef __PAU_REG00012_H_
#define __PAU_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::getScom(i_target, CS_SM3_SNP_MISC_TOPOLOGY_TABLE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]

//>> PUT_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return fapi2::putScom(i_target, CS_SM3_SNP_MISC_TOPOLOGY_TABLE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0]


//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
