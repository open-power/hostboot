/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00015.H $          */
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

#ifndef __MCC_REG00015_H_
#define __MCC_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[ATCL_CL_CLSCOM_MCEBUSCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCEBUSCL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATCL_CL_CLSCOM_MCEBUSCL]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCEBUSCL;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCEBUSCL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL]

//>> PUT_[ATCL_CL_CLSCOM_MCEBUSCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCEBUSCL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCEBUSCL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATCL_CL_CLSCOM_MCEBUSCL]


//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]
static inline bool GET_ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]

//>> SET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]

//>> GET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEBUSCL));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15,
           ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15]

//>> PREP_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_DECRYPT_CRYPTONONCEB]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEB;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEB]

//>> PUT_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_DECRYPT_CRYPTONONCEB]


//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> PREP_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_ENCRYPT_CRYPTONONCEA]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEA;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEA]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_ENCRYPT_CRYPTONONCEA]


//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>> PREP_[USTL_USTLLOLDROP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLLOLDROP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[USTL_USTLLOLDROP]

//>> GET_[USTL_USTLLOLDROP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLLOLDROP;
#endif
    return fapi2::getScom(i_target, USTL_USTLLOLDROP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[USTL_USTLLOLDROP]

//>> PUT_[USTL_USTLLOLDROP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLLOLDROP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return fapi2::putScom(i_target, USTL_USTLLOLDROP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[USTL_USTLLOLDROP]


//>> SET_[USTL_USTLLOLDROP_A_DROP_REASON]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLLOLDROP_A_DROP_REASON]

//>> SET_[USTL_USTLLOLDROP_A_DROP_REASON]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_A_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLLOLDROP_A_DROP_REASON]

//>> GET_[USTL_USTLLOLDROP_A_DROP_REASON]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLDROP_A_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return i_data.extractToRight<USTL_USTLLOLDROP_A_DROP_REASON,
           USTL_USTLLOLDROP_A_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLLOLDROP_A_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLLOLDROP_A_DROP_REASON]

//>> SET_[USTL_USTLLOLDROP_B_DROP_REASON]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLLOLDROP_B_DROP_REASON]

//>> SET_[USTL_USTLLOLDROP_B_DROP_REASON]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLDROP_B_DROP_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return o_data.insertFromRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLLOLDROP_B_DROP_REASON]

//>> GET_[USTL_USTLLOLDROP_B_DROP_REASON]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLDROP_B_DROP_REASON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLDROP));
#endif
    return i_data.extractToRight<USTL_USTLLOLDROP_B_DROP_REASON,
           USTL_USTLLOLDROP_B_DROP_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLLOLDROP_B_DROP_REASON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLLOLDROP_B_DROP_REASON]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
