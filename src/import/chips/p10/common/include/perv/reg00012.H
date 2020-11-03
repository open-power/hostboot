/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00012.H $         */
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

#ifndef __PERV_REG00012_H_
#define __PERV_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[COMP_INTR_HOST_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_COMP_INTR_HOST_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = COMP_INTR_HOST_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[COMP_INTR_HOST_MASK_REG]

//>> GET_[COMP_INTR_HOST_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_COMP_INTR_HOST_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = COMP_INTR_HOST_MASK_REG;
#endif
    return fapi2::getScom(i_target, COMP_INTR_HOST_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG]

//>> PUT_[COMP_INTR_HOST_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_COMP_INTR_HOST_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return fapi2::putScom(i_target, COMP_INTR_HOST_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[COMP_INTR_HOST_MASK_REG]


//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]
static inline bool GET_COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_0]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_1]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_2]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_3]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_4]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.insertFromRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.setBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline fapi2::buffer<uint64_t>& CLEAR_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return o_data.clearBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline fapi2::buffer<uint64_t>& GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.extractToRight<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]
static inline bool GET_COMP_INTR_HOST_MASK_REG_ERROR_MASK_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(COMP_INTR_HOST_MASK_REG));
#endif
    return i_data.getBit<COMP_INTR_HOST_MASK_REG_ERROR_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[COMP_INTR_HOST_MASK_REG_ERROR_MASK_5]

//>> PREP_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_RW]

//>> GET_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_RW]

//>> PUT_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_RW]

//>> PREP_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_WO_CLEAR]

//>> GET_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_WO_CLEAR]

//>> PUT_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_WO_CLEAR]

//>> PREP_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_WO_OR]

//>> GET_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_WO_OR]

//>> PUT_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_WO_OR]


//>> SET_[CPLT_CONF1_LANE_CFG_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_LANE_CFG_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_LANE_CFG_DC,
           CPLT_CONF1_LANE_CFG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_LANE_CFG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_LANE_CFG_DC]

//>> SET_[CPLT_CONF1_LANE_CFG_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_LANE_CFG_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_LANE_CFG_DC,
           CPLT_CONF1_LANE_CFG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_LANE_CFG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_LANE_CFG_DC]

//>> GET_[CPLT_CONF1_LANE_CFG_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_LANE_CFG_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_LANE_CFG_DC,
           CPLT_CONF1_LANE_CFG_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_LANE_CFG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_LANE_CFG_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> SET_[CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_OD_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_OD_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_OD_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_OD_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_OD_IOVALID_DC]

//>> GET_[CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_OD_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_OD_IOVALID_DC]

//>> GET_[CPLT_CONF1_OD_IOVALID_DC]
static inline bool GET_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[CPLT_CONF1_EN_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_EN_EQ_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_EN_EQ_DC,
           CPLT_CONF1_EN_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_EN_EQ_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_EN_EQ_DC]

//>> SET_[CPLT_CONF1_EN_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_EN_EQ_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_EN_EQ_DC,
           CPLT_CONF1_EN_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_EN_EQ_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_EN_EQ_DC]

//>> GET_[CPLT_CONF1_EN_EQ_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_EN_EQ_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_EN_EQ_DC,
           CPLT_CONF1_EN_EQ_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_EN_EQ_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_EN_EQ_DC]

//>> SET_[CPLT_CONF1_0_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_0_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_0_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_0_IOVALID_DC]

//>> SET_[CPLT_CONF1_0_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_0_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_0_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_0_IOVALID_DC]

//>> SET_[CPLT_CONF1_0_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_0_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_0_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_0_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_0_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_0_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_0_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_0_IOVALID_DC]

//>> GET_[CPLT_CONF1_0_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_0_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_0_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_0_IOVALID_DC]

//>> GET_[CPLT_CONF1_0_IOVALID_DC]
static inline bool GET_CPLT_CONF1_0_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_0_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_0_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_0_IOVALID_DC]

//>> SET_[CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_EV_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_EV_IOVALID_DC]

//>> SET_[CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_EV_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_EV_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_EV_IOVALID_DC]

//>> SET_[CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_EV_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_EV_IOVALID_DC]

//>> GET_[CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_EV_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_EV_IOVALID_DC]

//>> GET_[CPLT_CONF1_EV_IOVALID_DC]
static inline bool GET_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_EV_IOVALID_DC]

//>> SET_[CPLT_CONF1_1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_1_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_1_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_1_IOVALID_DC]

//>> SET_[CPLT_CONF1_1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_1_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_1_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_1_IOVALID_DC]

//>> SET_[CPLT_CONF1_1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_1_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_1_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_1_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_1_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_1_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_1_IOVALID_DC]

//>> GET_[CPLT_CONF1_1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_1_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_1_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_1_IOVALID_DC]

//>> GET_[CPLT_CONF1_1_IOVALID_DC]
static inline bool GET_CPLT_CONF1_1_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_1_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_1_IOVALID_DC]

//>> SET_[CPLT_CONF1_SWAP_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_SWAP_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_SWAP_DC,
           CPLT_CONF1_SWAP_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_SWAP_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_SWAP_DC]

//>> SET_[CPLT_CONF1_SWAP_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_SWAP_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_SWAP_DC,
           CPLT_CONF1_SWAP_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_SWAP_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_SWAP_DC]

//>> GET_[CPLT_CONF1_SWAP_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_SWAP_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_SWAP_DC,
           CPLT_CONF1_SWAP_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_SWAP_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_SWAP_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> SET_[CPLT_CONF1_NORTH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_NORTH_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_NORTH_DC,
           CPLT_CONF1_NORTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_NORTH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_NORTH_DC]

//>> SET_[CPLT_CONF1_NORTH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_NORTH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_NORTH_DC,
           CPLT_CONF1_NORTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_NORTH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_NORTH_DC]

//>> GET_[CPLT_CONF1_NORTH_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_NORTH_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_NORTH_DC,
           CPLT_CONF1_NORTH_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_NORTH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_NORTH_DC]

//>> SET_[CPLT_CONF1_2_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_2_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_2_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_2_IOVALID_DC]

//>> SET_[CPLT_CONF1_2_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_2_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_2_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_2_IOVALID_DC]

//>> SET_[CPLT_CONF1_2_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_2_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_2_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_2_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_2_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_2_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_2_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_2_IOVALID_DC]

//>> GET_[CPLT_CONF1_2_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_2_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_2_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_2_IOVALID_DC]

//>> GET_[CPLT_CONF1_2_IOVALID_DC]
static inline bool GET_CPLT_CONF1_2_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_2_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_2_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_2_IOVALID_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> SET_[CPLT_CONF1_3_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_3_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_3_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_3_IOVALID_DC]

//>> SET_[CPLT_CONF1_3_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_3_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_3_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_3_IOVALID_DC]

//>> SET_[CPLT_CONF1_3_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_3_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_3_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_3_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_3_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_3_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_3_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_3_IOVALID_DC]

//>> GET_[CPLT_CONF1_3_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_3_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_3_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_3_IOVALID_DC]

//>> GET_[CPLT_CONF1_3_IOVALID_DC]
static inline bool GET_CPLT_CONF1_3_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_3_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_3_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_3_IOVALID_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> SET_[CPLT_CONF1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_IOVALID_DC,
           CPLT_CONF1_IOVALID_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_IOVALID_DC]

//>> SET_[CPLT_CONF1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_IOVALID_DC,
           CPLT_CONF1_IOVALID_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_IOVALID_DC]

//>> GET_[CPLT_CONF1_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_IOVALID_DC,
           CPLT_CONF1_IOVALID_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_IOVALID_DC]

//>> SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_P_N1_PSI_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> CLEAR_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> GET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> GET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline bool GET_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_RATIO_OVERRIDE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_RATIO_OVERRIDE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_RATIO_OVERRIDE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_RATIO_OVERRIDE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_RATIO_OVERRIDE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_RATIO_OVERRIDE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> CLEAR_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_RATIO_OVERRIDE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_RATIO_OVERRIDE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> GET_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_RATIO_OVERRIDE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_RATIO_OVERRIDE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> GET_[CPLT_CONF1_RATIO_OVERRIDE_DC]
static inline bool GET_CPLT_CONF1_RATIO_OVERRIDE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_RATIO_OVERRIDE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_RATIO_OVERRIDE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_RATIO_OVERRIDE_DC]

//>> SET_[CPLT_CONF1_APP0_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP0_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP0_RATIO_DC,
           CPLT_CONF1_APP0_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_APP0_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP0_RATIO_DC]

//>> SET_[CPLT_CONF1_APP0_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP0_RATIO_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP0_RATIO_DC,
           CPLT_CONF1_APP0_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_APP0_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP0_RATIO_DC]

//>> GET_[CPLT_CONF1_APP0_RATIO_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_APP0_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_APP0_RATIO_DC,
           CPLT_CONF1_APP0_RATIO_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_APP0_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_APP0_RATIO_DC]

//>> SET_[CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_LP_RESET]

//>> SET_[CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_LP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_C_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_LP_RESET]

//>> SET_[CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_C_LP_RESET]

//>> CLEAR_[CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_C_LP_RESET]

//>> GET_[CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_C_LP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_C_LP_RESET]

//>> GET_[CPLT_CONF1_C_LP_RESET]
static inline bool GET_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_C_LP_RESET]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> CLEAR_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline bool GET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> CLEAR_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline bool GET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> CLEAR_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline bool GET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> CLEAR_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline bool GET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> SET_[CPLT_CONF1_APP1_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP1_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP1_RATIO_DC,
           CPLT_CONF1_APP1_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_APP1_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP1_RATIO_DC]

//>> SET_[CPLT_CONF1_APP1_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP1_RATIO_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP1_RATIO_DC,
           CPLT_CONF1_APP1_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_APP1_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP1_RATIO_DC]

//>> GET_[CPLT_CONF1_APP1_RATIO_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_APP1_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_APP1_RATIO_DC,
           CPLT_CONF1_APP1_RATIO_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_APP1_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_APP1_RATIO_DC]

//>> SET_[CPLT_CONF1_APP2_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP2_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP2_RATIO_DC,
           CPLT_CONF1_APP2_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CONF1_APP2_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP2_RATIO_DC]

//>> SET_[CPLT_CONF1_APP2_RATIO_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_APP2_RATIO_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_APP2_RATIO_DC,
           CPLT_CONF1_APP2_RATIO_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CONF1_APP2_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_APP2_RATIO_DC]

//>> GET_[CPLT_CONF1_APP2_RATIO_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_APP2_RATIO_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_APP2_RATIO_DC,
           CPLT_CONF1_APP2_RATIO_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CONF1_APP2_RATIO_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_APP2_RATIO_DC]

//>> PREP_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_RW]

//>> GET_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_RW]

//>> PUT_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_RW]

//>> PREP_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_WO_CLEAR]

//>> GET_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_WO_CLEAR]

//>> PUT_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_WO_CLEAR]

//>> PREP_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_WO_OR]

//>> GET_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_WO_OR]

//>> PUT_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_WO_OR]


//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline bool GET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline bool GET_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_EXPORT_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_EXPORT_FREEZE]

//>> CLEAR_[CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_EXPORT_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[CPLT_CTRL1_EXPORT_FREEZE]
static inline bool GET_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> CLEAR_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline bool GET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_STG_ACT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> CLEAR_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline bool GET_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_ROOT_CTRL2_COPY_REG]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
